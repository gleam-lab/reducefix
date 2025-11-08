#!/usr/bin/env python3
"""
OSS-Fuzz reducer builder - 使用 one-shot learning 生成测试用例缩减器

与外层 reducer_builder.py 保持一致的逻辑：
1. One-shot example (示例 reducer)
2. 统一的文件命名约定
3. 清晰的目录结构支持多模型对比
"""
import argparse
import json
import os
import sys
import traceback
from typing import Dict, List, Optional

sys.path.append(os.path.dirname(os.path.dirname(__file__)))
import llm  # type: ignore

# --- Configuration ---
EXAMPLE_CASE_ID = "benchmark-01"  # 用作 one-shot example 的案例
EXAMPLE_REDUCER_PATH = None  # 将在运行时查找已有的 reducer
TARGET_FILENAME = "reducer.py"
LLM_MAX_TOKENS = 4096
LLM_TEMPERATURE = 0.3


def resolve_case(case_id: str) -> Optional[Dict[str, str]]:
    """解析案例配置，支持 cases.json 和环境变量"""
    # 获取 oss_fuzz 目录的路径
    oss_fuzz_dir = os.path.dirname(os.path.abspath(__file__))
    cfg_path = os.path.join(oss_fuzz_dir, "cases.json")
    
    print(f"[Debug] Looking for cases.json at: {cfg_path}")
    print(f"[Debug] File exists: {os.path.isfile(cfg_path)}")
    
    case: Optional[Dict[str, str]] = None
    
    if os.path.isfile(cfg_path):
        try:
            with open(cfg_path, "r", encoding="utf-8") as f:
                data = json.load(f)
            case = data.get(case_id)
            print(f"[Debug] Found case in JSON: {case is not None}")
            if case:
                print(f"[Debug] Case target: {case.get('target')}")
        except Exception as e:
            print(f"[Error] Failed to load cases.json: {e}")
            case = None
    
    # 检查 case 是否有效（只要有 target 字段就行）
    if case and case.get("target"):
        return case
    
    # fallback to env
    if case_id == "pdfium" and os.environ.get("PDFIUM_BIN") and os.environ.get("PDFIUM_POC"):
        return {"target": "pdfium", "bin": os.environ["PDFIUM_BIN"], "poc": os.environ["PDFIUM_POC"]}
    if case_id == "harfbuzz" and os.environ.get("HARFBUZZ_BIN") and os.environ.get("HARFBUZZ_POC"):
        return {"target": "harfbuzz", "bin": os.environ["HARFBUZZ_BIN"], "poc": os.environ["HARFBUZZ_POC"]}
    
    return None


def read_example_reducer(case_id: str) -> Optional[str]:
    """Read example reducer code (for one-shot learning)"""
    base = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    
    # Try multiple possible paths
    possible_paths = [
        os.path.join(base, "oss_fuzz_results", "artifacts", case_id, "reducer_example.py"),
        os.path.join(base, "oss_fuzz_results", "artifacts", case_id, "qwen-plus", "reducer.py"),
        os.path.join(base, "oss_fuzz_results", "example_reducer.py"),
    ]
    
    for path in possible_paths:
        if os.path.exists(path):
            try:
                with open(path, 'r', encoding='utf-8') as f:
                    content = f.read()
                print(f"[Info] Successfully read example reducer: {path} ({len(content)} chars)")
                return content
            except IOError as e:
                print(f"[Warning] Failed to read example reducer {path}: {e}", file=sys.stderr)
                continue
    
    print(f"[Warning] Example reducer not found, using zero-shot mode", file=sys.stderr)
    return None


def get_case_description(case: Dict[str, str]) -> str:
    """生成案例描述（用于 prompt）"""
    target = case.get("target", "unknown")
    desc = case.get("description", "")
    size = case.get("size_bytes", 0)
    
    lines = []
    lines.append(f"Target: {target}")
    if desc:
        lines.append(f"Description: {desc}")
    if size:
        lines.append(f"Original Size: {size} bytes")
    
    return "\n".join(lines)


def build_generation_prompt(
    target_name: str,
    example_case: Optional[Dict[str, str]] = None,
    example_reducer_code: Optional[str] = None,
    format_info: Optional[str] = None,
) -> List[Dict[str, str]]:
    """构建 LLM prompt（为整个 target 生成通用 reducer）
    
    Args:
        target_name: 目标项目名称（如 pdfium, harfbuzz）
        example_case: 示例案例信息
        example_reducer_code: 示例 reducer 代码
        format_info: 实际文件的格式信息（文件头部、类型等）
    """
    
    # Generate target-specific hints
    target_descriptions = {
        "pdfium": {
            "format": "PDF files",
            "hints": [
                "PDF format: consists of objects, streams, and cross-reference tables",
                "Priority strategy: reduce by lines/blocks; preserve object structure (%%PDF, obj/endobj, xref, trailer)",
                "Special handling: apply ASCIIHexDecode for stream representation to enable text-based reduction",
                "Keep essentials: document header, catalog, page object tree, specific objects triggering the bug"
            ]
        },
        "harfbuzz": {
            "format": "Font files (TrueType/OpenType)",
            "hints": [
                "Font format: composed of multiple tables",
                "Priority strategy: block-level reduction first, maintain table structure integrity",
                "Keep essentials: required tables (head, hhea, maxp, name, etc.) and tables triggering the bug",
                "Note: font files are binary format, should be processed by blocks"
            ]
        },
        "libxml2": {
            "format": "XML files (eXtensible Markup Language)",
            "hints": [
                "XML format: hierarchical tree structure with elements, attributes, and text nodes",
                "Priority strategy: **structure-aware reduction** - understand XML syntax and maintain well-formedness",
                "Multi-stage approach:",
                "  1. Element-level: Try removing entire XML elements (with their children) while keeping document well-formed",
                "  2. Attribute-level: Remove attributes from elements that still trigger the bug",
                "  3. Text-level: Reduce text content within elements",
                "  4. Fine-tuning: Line-by-line reduction for remaining content",
                "Key requirements:",
                "  - Maintain XML well-formedness: every opening tag must have closing tag",
                "  - Preserve XML declaration (<?xml...?>) if present",
                "  - Keep root element structure",
                "  - Use regex or simple parsing to identify element boundaries",
                "Example strategies:",
                "  - Match <tag>...</tag> pairs and try removing them",
                "  - Match <tag attr='value'> and try removing attributes",
                "  - For namespaces, preserve namespace declarations if used elements depend on them",
                "Performance tips:",
                "  - Start with outermost elements (depth-first removal)",
                "  - Use greedy removal: try removing multiple elements at once",
                "  - Balance between syntax validation and speed (prefer regex over full XML parsing for performance)"
            ]
        },
        "poppler": {
            "format": "PDF files (Portable Document Format)",
            "hints": [
                "PDF format: hybrid text/binary format with objects, streams, dictionaries",
                "Priority strategy: object-level reduction preserving PDF structure",
                "Key components:",
                "  - Header: %PDF-x.y (must keep)",
                "  - Objects: N M obj ... endobj (can try removing individual objects)",
                "  - Cross-reference table: xref (regenerate or keep minimal)",
                "  - Trailer: trailer dict with /Root reference",
                "Reduction stages:",
                "  1. Object removal: Try removing obj/endobj blocks one by one",
                "  2. Stream reduction: Reduce content within streams",
                "  3. Dictionary pruning: Remove unnecessary key-value pairs from dictionaries",
                "  4. Line-level fine-tuning",
                "Special notes:",
                "  - Maintain /Root, /Pages references to avoid immediate crashes",
                "  - Binary streams can be replaced with empty or minimal content",
                "  - Focus on objects that trigger the bug, not rendering correctness"
            ]
        },
        "mupdf": {
            "format": "PDF files (handled by MuPDF)",
            "hints": [
                "Similar to poppler, but MuPDF is more lenient with malformed PDFs",
                "Can be more aggressive in object removal",
                "Priority: object-level reduction, then stream content reduction",
                "MuPDF often crashes on specific object types or stream contents",
                "Try removing objects by type (/Type key) to identify bug source"
            ]
        },
        "imagemagick": {
            "format": "Image files (various formats: PNG, JPEG, GIF, TIFF, etc.)",
            "hints": [
                "Image formats are mostly binary with specific headers",
                "Priority strategy: chunk-based reduction preserving file headers",
                "Common approach:",
                "  1. Identify and preserve file signature/magic bytes (first 8-16 bytes)",
                "  2. Try reducing image dimensions in metadata if parseable",
                "  3. Block-level removal of pixel data",
                "  4. Keep critical chunks/segments that identify image structure",
                "Format-specific notes:",
                "  - PNG: preserve IHDR chunk, try removing other chunks (tEXt, iTXt, etc.)",
                "  - JPEG: preserve SOI/EOI markers, reduce segments between",
                "  - GIF: preserve header and logical screen descriptor",
                "Since format varies, use block-based reduction as fallback"
            ]
        },
        "php-src": {
            "format": "PHP source code files",
            "hints": [
                "PHP code: text-based programming language with <?php ?> tags",
                "Priority strategy: syntax-aware reduction maintaining valid PHP",
                "Multi-stage approach:",
                "  1. Function/class-level: Remove entire functions or classes not needed for bug",
                "  2. Statement-level: Remove individual statements or blocks",
                "  3. Expression-level: Simplify expressions while keeping syntax valid",
                "  4. Line-level fine-tuning",
                "Key requirements:",
                "  - Maintain PHP open tag <?php",
                "  - Keep balanced braces {}, parentheses (), brackets []",
                "  - Preserve semicolons for statement termination",
                "  - Keep variable declarations if used later",
                "Tips:",
                "  - Use regex to identify function/class boundaries",
                "  - Try removing comments and whitespace first",
                "  - Focus on minimal code that triggers the bug, ignore correctness"
            ]
        },
        "mbedtls": {
            "format": "Cryptographic data (certificates, keys, encrypted messages, ASN.1 structures)",
            "hints": [
                "mbedTLS processes various cryptographic formats: X.509 certificates (PEM/DER), private/public keys, TLS handshake messages, ASN.1 encoded data",
                "Priority strategy: **format-aware reduction** preserving cryptographic structure",
                "Common input types:",
                "  - PEM format: Base64-encoded with -----BEGIN/END----- markers",
                "  - DER format: Binary ASN.1 encoding",
                "  - Raw binary: TLS records, handshake messages, encrypted data",
                "Multi-stage approach:",
                "  1. **Format detection**: Identify if PEM (text) or DER/binary",
                "  2. **PEM handling** (if text with -----BEGIN-----):",
                "     - Preserve BEGIN/END markers",
                "     - Try reducing Base64 content between markers",
                "     - For multiple PEM blocks, try removing entire blocks",
                "  3. **ASN.1/DER handling** (if binary with 0x30 tag):",
                "     - ASN.1 uses TLV (Tag-Length-Value) structure",
                "     - Try removing TLV sequences while maintaining structure",
                "     - Preserve essential tags (SEQUENCE, INTEGER, OCTET STRING)",
                "  4. **Generic binary** (if no clear structure):",
                "     - Block-level reduction (try 256-byte, 128-byte, 64-byte blocks)",
                "     - Preserve first 16-32 bytes (often contains format signature)",
                "  5. **Fine-tuning**: Line-level (for PEM) or byte-level (for binary)",
                "Key observations:",
                "  - mbedTLS bugs often triggered by malformed lengths, invalid tags, or boundary conditions",
                "  - Focus on reducing data size while keeping structural anomalies that trigger bugs",
                "  - For PEM: invalid Base64 or truncated encoding can trigger bugs",
                "  - For DER: incorrect length fields or unexpected tag sequences are common triggers",
                "Detection heuristics:",
                "  - PEM: starts with '-----BEGIN' (ASCII text)",
                "  - DER/ASN.1: starts with 0x30 (SEQUENCE tag) or 0x02 (INTEGER)",
                "  - TLS handshake: starts with 0x16 (handshake record type)",
                "  - X.509 cert (DER): 0x30 followed by length, then 0x30 again (SEQUENCE of SEQUENCE)",
                "Performance tips:",
                "  - For PEM, work with decoded binary first, then re-encode",
                "  - For binary, use greedy block removal before fine-grained reduction",
                "  - Balance between preserving cryptographic validity and aggressive reduction"
            ]
        },
        "gdal": {
            "format": "Geospatial data (TIFF/GeoTIFF, raster images, vector formats)",
            "hints": [
                "GDAL processes various geospatial and image formats: TIFF, GeoTIFF, PNG, JPEG, GIF, HDF, netCDF, Shapefile, etc.",
                "Most common: TIFF format (Tagged Image File Format) - hybrid binary format with directory structure",
                "Priority strategy: **structure-aware reduction** preserving TIFF/image file integrity",
                "TIFF structure basics:",
                "  - Header (8-16 bytes): Byte order (II/MM) + magic number (42) + offset to first IFD",
                "  - IFD (Image File Directory): Contains tags describing image properties and data location",
                "  - Image data: Can be strips or tiles, possibly compressed (PackBits, LZW, JPEG, etc.)",
                "  - Multiple IFDs possible (multi-page TIFF)",
                "Multi-stage approach:",
                "  1. **Format detection**: Check TIFF signature (II/MM + 0x002A or 0x2A00)",
                "  2. **IFD-level reduction** (if multi-IFD TIFF):",
                "     - Try removing entire IFDs (keep first/main IFD)",
                "     - Focus on IFD that triggers the bug",
                "  3. **Strip/Tile reduction**:",
                "     - TIFF images divided into strips or tiles",
                "     - Try reducing number of strips/tiles",
                "     - Try reducing strip/tile data size",
                "  4. **Tag reduction**:",
                "     - Try removing non-essential tags from IFD",
                "     - Keep critical tags: ImageWidth, ImageLength, StripOffsets, StripByteCounts, Compression",
                "  5. **Image dimension reduction** (if parseable):",
                "     - Reduce ImageWidth/ImageLength in IFD",
                "     - Adjust strip offsets and byte counts accordingly",
                "  6. **Block-level fallback** (for unknown formats):",
                "     - Preserve file signature (first 8 bytes)",
                "     - Block-based reduction of remaining data",
                "Key observations:",
                "  - GDAL bugs often in decoders/decompressors (PackBits, LZW, JPEG, etc.)",
                "  - Malformed IFD structures, invalid tag values, or truncated data can trigger bugs",
                "  - For PackBits: focus on compressed strip data, may need incomplete/malformed compression",
                "  - For other formats (PNG, JPEG): preserve file signature and critical chunks/segments",
                "Detection heuristics:",
                "  - TIFF: starts with 'II' (0x4949, little-endian) or 'MM' (0x4D4D, big-endian)",
                "  - PNG: starts with 0x89504E47",
                "  - JPEG: starts with 0xFFD8",
                "  - GIF: starts with 'GIF8'",
                "Performance tips:",
                "  - For TIFF: parse IFD structure first, enable targeted reduction",
                "  - For compressed formats: focus on compressed data regions",
                "  - Balance between format validity and aggressive reduction",
                "  - GDAL is lenient with malformed files, so can be more aggressive"
            ]
        },
        "open62541": {
            "format": "Network protocol messages (mDNS, OPC UA, structured binary packets)",
            "hints": [
                "open62541 is an OPC UA stack that also uses mDNS for service discovery",
                "Input formats: **small, structured binary messages** (typically <1KB)",
                "Common characteristics:",
                "  - Fixed-size headers with length/count fields",
                "  - Multiple records/sections within the message",
                "  - Heavy use of length-prefixed strings and variable-length fields",
                "  - Often contains padding bytes (0x00, 0x20/space, 0xFF)",
                "Priority strategy: **field-aware reduction** exploiting message structure",
                "mDNS message structure (DNS-like):",
                "  - Header (12 bytes): Transaction ID, flags, counts for question/answer/authority/additional sections",
                "  - Question section: Name (variable) + Type (2 bytes) + Class (2 bytes)",
                "  - Answer/Authority/Additional sections: Name + Type + Class + TTL (4 bytes) + RData length + RData",
                "  - Names use DNS compression (pointers to previous names)",
                "OPC UA binary messages:",
                "  - Message header with message type and size",
                "  - Chunks with sequence numbers",
                "  - Encoded data using UA Binary encoding (TLV-like)",
                "Multi-stage reduction approach:",
                "  1. **Byte-level DDMin** (CRITICAL for small files):",
                "     - Since files are small (<512 bytes), directly use byte-by-byte DDMin",
                "     - Try removing individual bytes or small byte ranges",
                "     - This is THE MOST EFFECTIVE strategy for small structured messages",
                "  2. **Padding removal**:",
                "     - Strip trailing padding (0x00, 0x20, 0xFF)",
                "     - Remove internal padding blocks (>=4 consecutive padding bytes)",
                "  3. **Record/section reduction** (if parseable):",
                "     - Parse header to identify record counts",
                "     - Try reducing record counts and removing corresponding data",
                "     - Focus on sections that might trigger the bug",
                "  4. **Length field adjustment** (advanced):",
                "     - If header contains length/count fields, try reducing them",
                "     - Adjust total message size, record counts, string lengths",
                "     - This can trigger parsing errors and buffer overflow bugs",
                "  5. **Byte-value simplification**:",
                "     - Try replacing byte ranges with simpler patterns (all 0x00, all 0xFF, all 0x20)",
                "     - Focus on non-structural bytes (data payloads, not length fields)",
                "Key observations:",
                "  - Bugs often triggered by: invalid length fields, out-of-bounds pointers, malformed records",
                "  - Parser bugs sensitive to specific byte sequences at specific offsets",
                "  - File size itself may be important (truncation bugs)",
                "  - DON'T use 256-byte chunk DDMin for files <512 bytes (causes infinite loop)",
                "Detection heuristics:",
                "  - Small file size (<1KB)",
                "  - High ratio of padding bytes (0x00, 0x20, 0xFF)",
                "  - Presence of length fields in first few bytes",
                "  - No clear text structure (mostly binary)",
                "Performance tips:",
                "  - **For files <512 bytes: ALWAYS use byte-level DDMin first**",
                "  - Start with aggressive byte removal, then fine-tune",
                "  - Test truncation early (many bugs are size-dependent)",
                "  - Use binary search for byte-level reduction",
                "Implementation warning:",
                "  - **NEVER** use block-based (256-byte) DDMin on small files",
                "  - Small files need byte-granularity or small chunks (1-16 bytes)",
                "  - Implement adaptive chunk sizing based on file size"
            ]
        },
        "ffmpeg": {
            "format": "Media container files and codec-specific bitstreams (various video/audio formats)",
            "hints": [
                "FFmpeg processes diverse multimedia formats: containers (MP4, AVI, MKV), codecs (H.264, VP9, AAC), images, subtitle formats",
                "Input types vary GREATLY: some are well-structured containers, others are raw codec bitstreams",
                "Common patterns in fuzzer-generated test cases:",
                "  - Small files (1-10KB) with artificial padding or repeated patterns",
                "  - Fuzzer signatures: 'UZZ-T', 'UZZG', 'FUZZ' markers appended by OSS-Fuzz",
                "  - High ratio of specific bytes: spaces (0x20), 0xFF, 0xF9, backticks (0x60)",
                "  - Malformed headers, truncated streams, or crafted invalid data",
                "**CRITICAL insight for FFmpeg fuzzer test cases**:",
                "  - Many fuzzer inputs are MINIMAL TRIGGER FILES already highly reduced by fuzzer",
                "  - Traditional format-aware reduction (removing 'non-essential' structures) may fail",
                "  - Bug often triggered by SPECIFIC BYTE SEQUENCES at SPECIFIC OFFSETS",
                "  - Codec bugs are extremely sensitive to bitstream corruption",
                "",
                "**🎯 TARGET: 50%+ COMPRESSION - Multi-stage strategy (in priority order)**:",
                "",
                "**Stage 0: Aggressive prefix reduction** ⭐⭐⭐⭐⭐ (HIGHEST PRIORITY - 必须实现)",
                "  - STEP 1: First try removing ENTIRE second half immediately:",
                "    ```python",
                "    # Try keeping only first 50%",
                "    if test_fn(data[:len(data)//2]):",
                "        data = data[:len(data)//2]  # SUCCESS: 50% reduction immediately!",
                "    ```",
                "  - STEP 2: If step 1 succeeded, try 25%, 12.5%, etc.",
                "  - STEP 3: Then use binary search to find exact minimum:",
                "    ```python",
                "    low = len(data) // 2  # Start from 50%",
                "    high = len(data)",
                "    best = len(data)",
                "    while low <= high:",
                "        mid = (low + high) // 2",
                "        if test_fn(data[:mid]):",
                "            best = mid",
                "            high = mid - 1  # Try shorter",
                "        else:",
                "            low = mid + 1",
                "    data = data[:best]",
                "    ```",
                "  - Expected: 50-70% compression for typical fuzzer inputs",
                "  - 这是最重要的阶段，必须首先实现！",
                "",
                "**Stage 1: Binary shrink repetitive byte runs** ⭐⭐⭐⭐⭐",
                "  - Fuzzer files often have long runs (e.g., 601 consecutive backticks)",
                "  - For each run >=16 bytes, use BINARY SEARCH to find minimum needed",
                "  - Algorithm:",
                "    ```",
                "    Find run of same byte (length >= 16)",
                "    Use binary search to shrink: try keeping 1, 2, 4, 8, ... bytes",
                "    Keep minimum that still passes test_fn",
                "    ```",
                "  - DON'T remove chunk by chunk (too slow), shrink the WHOLE run at once",
                "  - Expected: 5-10% additional compression",
                "",
                "**Stage 2: Remove fuzzer signatures and trailing padding**:",
                "  - Remove UZZ-T, UZZG, FUZZ markers and surrounding bytes",
                "  - Strip trailing runs of padding bytes",
                "  - Expected: 0.5-2% compression",
                "",
                "**Stage 3: Adaptive DDMin with region awareness** ⭐⭐⭐⭐:",
                "  - Identify repetitive regions (runs of same byte >32)",
                "  - Use DIFFERENT chunk sizes for different regions:",
                "    • Repetitive regions: larger chunks (256, 128, 64)",
                "    • Sparse regions: smaller chunks (32, 16, 8)",
                "  - File size based chunk selection:",
                "    • 0-1KB: [64, 32, 16, 8, 4]",
                "    • 1-5KB: [256, 128, 64, 32, 16, 8]",
                "    • 5-20KB: [512, 256, 128, 64, 32, 16]",
                "    • >20KB: [2048, 1024, 512, 256, 128, 64]",
                "  - Multi-pass: keep trying each chunk size until no progress",
                "  - Expected: 10-20% additional compression",
                "",
                "**Stage 4: Aggressive zero-fill optimization** ⭐⭐⭐⭐⭐ (关键策略):",
                "  - 很多bug不关心具体数据内容，只关心文件结构和特定位置",
                "  - STEP 1: 尝试将整个后半部分替换为0x00:",
                "    ```python",
                "    mid = len(data) // 2",
                "    candidate = data[:mid] + bytes(len(data) - mid)",
                "    if test_fn(candidate):",
                "        data = candidate  # 50% data zeroed!",
                "    ```",
                "  - STEP 2: 尝试将文件分成4块，逐个尝试零填充每一块:",
                "    ```python",
                "    chunk_size = len(data) // 4",
                "    for i in range(4):",
                "        start = i * chunk_size",
                "        end = start + chunk_size if i < 3 else len(data)",
                "        candidate = data[:start] + bytes(end-start) + data[end:]",
                "        if test_fn(candidate):",
                "            data = candidate  # This quarter zeroed!",
                "    ```",
                "  - STEP 3: 尝试更小的块 (512字节、256字节)",
                "  - Expected: 20-50% data can often be zeroed",
                "  - 注意：零填充不减少文件大小，但简化内容，便于后续DDMin删除",
                "",
                "**Stage 5: Fine-grained DDMin** (if needed):",
                "  - Only if above stages didn't achieve >40% compression",
                "  - Try smaller chunks (4, 2, 1 bytes)",
                "  - Stop after 5000-10000 tests to avoid infinite grinding",
                "",
                "**IMPLEMENTATION EXAMPLES**:",
                "",
                "**Example 1: Aggressive prefix reduction (Stage 0) - 必须实现:**",
                "```python",
                "def aggressive_prefix_reduction(data, test_fn):",
                "    '''Try removing chunks from the end, starting with 50%'''",
                "    if len(data) < 100:",
                "        return data",
                "    ",
                "    # Step 1: Try 50%, 25%, 12.5%",
                "    for fraction in [0.5, 0.25, 0.125]:",
                "        keep_len = int(len(data) * fraction)",
                "        if keep_len > 0 and test_fn(data[:keep_len]):",
                "            data = data[:keep_len]",
                "            print(f'  ✓ Kept only {fraction*100}% of file!')",
                "    ",
                "    # Step 2: Binary search for exact minimum",
                "    low, high = len(data) // 2, len(data)",
                "    best = len(data)",
                "    while low <= high:",
                "        mid = (low + high) // 2",
                "        if test_fn(data[:mid]):",
                "            best = mid",
                "            high = mid - 1",
                "        else:",
                "            low = mid + 1",
                "    return data[:best]",
                "```",
                "",
                "**Example 2: Aggressive zero-fill (Stage 4) - 必须实现:**",
                "```python",
                "def aggressive_zero_fill(data, test_fn):",
                "    '''Try replacing large chunks with zeros'''",
                "    result = data",
                "    ",
                "    # Step 1: Try zeroing entire second half",
                "    mid = len(result) // 2",
                "    candidate = result[:mid] + bytes(len(result) - mid)",
                "    if test_fn(candidate):",
                "        result = candidate",
                "        print(f'  ✓ Zeroed second half!')",
                "    ",
                "    # Step 2: Try zeroing each quarter",
                "    chunk_size = len(result) // 4",
                "    for i in range(4):",
                "        start = i * chunk_size",
                "        end = start + chunk_size if i < 3 else len(result)",
                "        candidate = result[:start] + bytes(end - start) + result[end:]",
                "        if test_fn(candidate):",
                "            result = candidate",
                "            print(f'  ✓ Zeroed quarter {i+1}/4')",
                "    ",
                "    # Step 3: Try smaller blocks (512, 256 bytes)",
                "    for block_size in [512, 256]:",
                "        i = 0",
                "        while i < len(result):",
                "            end = min(i + block_size, len(result))",
                "            candidate = result[:i] + bytes(end - i) + result[end:]",
                "            if test_fn(candidate):",
                "                result = candidate",
                "            else:",
                "                i += block_size",
                "    ",
                "    return result",
                "```",
                "",
                "Binary shrink repetitive runs:",
                "```python",
                "def shrink_runs(data, test_fn):",
                "    result = data",
                "    changed = True",
                "    while changed:",
                "        changed = False",
                "        i = 0",
                "        while i < len(result) - 16:",
                "            # Find run",
                "            run_len = 1",
                "            while i+run_len < len(result) and result[i] == result[i+run_len]:",
                "                run_len += 1",
                "            ",
                "            if run_len >= 16:",
                "                byte_val = result[i]",
                "                # Binary search for minimum",
                "                low, high = 1, run_len",
                "                best = run_len",
                "                while low <= high:",
                "                    mid = (low + high) // 2",
                "                    candidate = result[:i] + bytes([byte_val])*mid + result[i+run_len:]",
                "                    if test_fn(candidate):",
                "                        best = mid",
                "                        high = mid - 1",
                "                    else:",
                "                        low = mid + 1",
                "                if best < run_len:",
                "                    result = result[:i] + bytes([byte_val])*best + result[i+run_len:]",
                "                    changed = True",
                "                    break",
                "            i += run_len",
                "    return result",
                "```",
                "",
                "**Format-specific notes** (if format can be identified):",
                "  - **MP4/MOV**: Remove atoms/boxes one by one, preserve moov/mdat",
                "  - **AVI**: Remove chunks, preserve RIFF structure",
                "  - **MPEG-TS**: Remove packets (188-byte units), preserve PAT/PMT",
                "  - **H.264/H.265 bitstreams**: Remove NAL units, preserve SPS/PPS",
                "  - **Image files (PNG, JPEG, GIF)**: Remove chunks/segments, preserve headers",
                "  - **Unknown/raw codec data**: Use the binary search strategies above",
                "",
                "**Common FFmpeg fuzzer bugs patterns**:",
                "  - Buffer overflows in codec decoders (triggered by specific byte sequences)",
                "  - Out-of-bounds reads in demuxers (triggered by malformed headers)",
                "  - Integer overflows in size calculations",
                "  - Crashes on truncated/incomplete frames",
                "",
                "**Performance tips**:",
                "  - FFmpeg test execution is FAST (usually <100ms), so test count is not the bottleneck",
                "  - Binary search is O(log N), much faster than linear scan",
                "  - Stage 0 (binary search min length) typically needs only 10-15 tests for 6KB file",
                "  - Prioritize EFFECTIVE reduction over test count minimization",
                "",
                "**Implementation critical points (必读):**:",
                "  - ⭐⭐⭐ MUST implement Stage 0 (aggressive prefix reduction) - 直接尝试删除50%",
                "  - ⭐⭐⭐ MUST implement Stage 4 (aggressive zero-fill) - 尝试将50%数据置零",
                "  - These two stages are NON-NEGOTIABLE - 这是实现50%目标的关键",
                "  - Stage 0应该首先尝试 test_fn(data[:len(data)//2]) - 一次测试就能知道能否删除一半",
                "  - Stage 4应该首先尝试 test_fn(data[:mid] + bytes(len(data)-mid)) - 一次测试就能知道能否零填充一半",
                "  - Handle edge cases: empty input, single-byte input",
                "  - For each stage, report progress: 'Stage N: X → Y bytes (Z% reduction)'",
                "  - 每个stage结束后必须输出压缩率，如果某个stage没有效果要明确说明",
                "",
                "**Expected results (REALISTIC targets)**:",
                "  - Files with trailing garbage: 50-70% compression (via Stage 0)",
                "  - Files with long repetitive runs: 20-40% compression (via Stage 1)",
                "  - Well-structured containers: 40-80% compression (combined)",
                "  - Already-minimal fuzzer inputs: 10-30% compression",
                "  - TARGET: At least 50% compression for typical fuzzer inputs"
            ]
        }
    }
    
    target_info = target_descriptions.get(target_name, {
        "format": "binary files",
        "hints": [
            "General strategy: block-level greedy removal first, then granularity doubling search, finally line-level fine-tuning",
            "Preserve essential parts that trigger the bug"
        ]
    })
    
    format_desc = target_info["format"]
    hints = target_info["hints"]
    guidance = "\n".join(f"  - {h}" for h in hints)
    
    system_prompt = f"""You are an expert in test case reduction with deep understanding of file formats and data structures.

Your task: Generate a **format-aware** reducer for {target_name} that processes {format_desc}.

**Your approach must be**:
1. **Analyze first**: You will receive actual file format analysis (type, structure, characteristics)
2. **Think strategically**: Identify the natural reduction units for this specific format
3. **Design multi-stage**: Create stages from coarse-grained to fine-grained reduction
4. **Implement intelligently**: Use format-specific patterns (regex, delimiters, structure markers)
5. **Stay generic**: Must work for ALL {target_name} test cases, not just the analyzed one

**Required function signature:**
```python
def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    \"\"\"
    Format-aware test case reducer for {target_name}
    
    Args:
      - input_bytes: Original input data ({format_desc})
      - test_fn: Oracle function - returns True if candidate still reproduces the bug
      - verbose: Enable detailed progress output (default True)
    
    Strategy:
      - Stage 1: Remove large structural units (format-specific)
      - Stage 2: Remove smaller units or attributes
      - Stage 3: Reduce content within remaining units  
      - Stage 4: Fine-grained reduction (lines/bytes)
      - Each stage must validate candidates using test_fn
    
    Output:
      - Smallest input that still satisfies test_fn
      - Progress with [ReduceFix] prefix
      - Metrics: test count, time, reduction rate
    \"\"\"
    import time
    # Your format-aware implementation here
```

**Output requirements:**
- Only output Python code block (```python ... ```)
- No explanations outside code
- Include progress output inside implementation

**Common pitfalls to avoid:**
- ❌ f-string cannot contain backslash inside curly braces
  Example of WRONG code: f-string with backslash-n inside the braces
- ✅ Calculate string operations first, then use result in f-string
  Example: temp = newline_join(x); then use temp in f-string
- ❌ Mixing bytes and str types inconsistently
- ✅ Choose bytes or str and use consistently throughout

**CRITICAL: Progress output requirements (MUST follow strictly):**

1. **Count ALL tests** (success OR failure):
   ```python
   test_count = 0  # Initialize once
   # In EVERY test (regardless of result):
   test_count += 1
   if test_fn(candidate):
       # success
   else:
       # failure
   ```

2. **Output progress regularly** (every 100-200 tests):
   ```python
   if test_count % 100 == 0 and verbose:
       elapsed = time.time() - start_time
       # Use f-string to show: test count, current size, elapsed time
       print(f"  [ReduceFix] Progress: {{test_count}} tests, {{len(current)}} bytes, {{elapsed:.1f}}s")
   ```

3. **MUST print at stage transitions**:
   ```python
   if verbose:
       # Show stage number and name
       print(f"[ReduceFix] Stage {{N}}: {{stage_name}}")
       print(f"  Starting size: {{len(current)}} bytes")
   ```

4. **MUST print after each major step** (e.g., each chunk size):
   ```python
   if verbose:
       # Print EVEN IF no reduction
       print(f"  [ReduceFix] Chunk {{chunk_size}}: {{before}} → {{after}} bytes")
   ```

**Progress output template:**
```
[ReduceFix] Starting reduction
[ReduceFix] Original size: 100109 bytes

[ReduceFix] Stage 1: Remove fuzzer signatures
  Starting size: 100109 bytes
  [ReduceFix] Progress: 100 tests, 98000 bytes, 3.2s
  [ReduceFix] ✓ Removed signature at offset 98000
[ReduceFix] Stage 1 complete: 100109 → 98000 bytes (2.1% reduction)

[ReduceFix] Stage 2: DDMin reduction
  Starting size: 98000 bytes
  [ReduceFix] Chunk sizes: [256, 64, 16, 4, 1]
  [ReduceFix] Progress: 200 tests, 95000 bytes, 6.5s
  [ReduceFix] Chunk 256: 98000 → 95000 bytes (3.1% reduction)
  [ReduceFix] Progress: 400 tests, 92000 bytes, 13.1s
  [ReduceFix] Chunk 64: 95000 → 92000 bytes (3.2% reduction)
  [ReduceFix] Progress: 800 tests, 90000 bytes, 26.3s
  [ReduceFix] Chunk 16: 92000 → 90000 bytes (2.2% reduction)
  [ReduceFix] Chunk 4: 90000 → 90000 bytes (no change)
  [ReduceFix] Chunk 1: 90000 → 89500 bytes (0.6% reduction)
[ReduceFix] Stage 2 complete: 98000 → 89500 bytes (8.7% reduction)

[ReduceFix] Complete: 100109 → 89500 bytes (10.6% reduction)
[ReduceFix] Total tests: 1234, total time: 45.6s
```

**WHY this is critical:**
- User needs to see progress to know the reducer is working
- Without progress, they think it's stuck after 5000+ tests
- Progress helps debug if a stage is inefficient

**Critical DDMin implementation pattern** (for reference - adapt to your format):
```python
def ddmin_pass(data: bytes, chunk_size: int, test_fn) -> bytes:
    \"\"\"One pass of DDMin: try removing each chunk of given size\"\"\"
    if len(data) <= chunk_size:
        return data
    
    current = data
    i = 0
    while i < len(current):
        chunk_start = i
        chunk_end = min(i + chunk_size, len(current))
        
        # Try removing this chunk
        candidate = current[:chunk_start] + current[chunk_end:]
        if len(candidate) > 0 and test_fn(candidate):
            current = candidate  # Success! Continue from same position
            # DON'T increment i - re-check this position with new data
        else:
            i += chunk_size  # Failed, move to next chunk
    
    return current

# Multi-pass with decreasing chunk sizes
data = input_bytes
for chunk_size in [256, 64, 16, 4, 1]:  # Adapt based on file size
    changed = True
    while changed:  # Keep trying until no more progress
        before = len(data)
        data = ddmin_pass(data, chunk_size, test_fn)
        changed = (len(data) < before)
```

**Critical**: Your reducer's effectiveness depends on:
1. Understanding the format structure (if identifiable)
2. Using appropriate algorithms (DDMin for unknown/minimal files, format-aware for structured files)
3. Adaptive strategy based on file analysis (YOU WILL receive detailed analysis, use it!)
"""
    
    # 构建 user prompt
    if example_reducer_code and example_case:
        # 有示例的 one-shot learning
        example_desc = get_case_description(example_case)
        
        format_section = ""
        if format_info:
            format_section = f"""

## Actual Test Case Analysis:
{format_info}

**Think step-by-step**:
1. Examine the format analysis - What type of file is this? (text/binary, structured/unstructured)
2. Based on the format, identify natural "reduction units":
   
   | Format Type | Example Units | Typical Patterns |
   |-------------|---------------|------------------|
   | XML/HTML | elements, attributes, text | `<tag>...</tag>`, `attr="value"` |
   | PDF | objects, streams, dictionaries | `N M obj...endobj`, `stream...endstream` |
   | JSON | objects, arrays, key-value | `{...}`, `[...]`, `"key": value` |
   | Images (PNG/JPEG/GIF) | chunks, segments, metadata | file signature + chunk structure |
   | Fonts (TTF/OTF) | tables, glyph data | table directory + table data |
   | Source code (PHP/C/JS) | functions, statements, expressions | function boundaries, block delimiters |
   | Plain text | paragraphs, lines, words | newline delimiters |
   | Binary data | fixed blocks, variable chunks | no clear structure, use byte-level |

3. Design multi-stage strategy appropriate for the identified format:
   - Stage 1: Remove large structural units (format-specific)
   - Stage 2: Remove smaller units or components
   - Stage 3: Reduce content within remaining structures
   - Stage 4: Fine-grained reduction (lines/bytes as fallback)

4. Implement using appropriate techniques for the format

**Critical**: The example below shows METHODOLOGY (interface, multi-stage, validation),
NOT the specific strategy. YOU must design stages based on the actual format analysis above!
"""
        
        user_prompt = f"""Below is a REFERENCE EXAMPLE showing reducer structure and methodology:

# Example Reducer (shows approach, NOT necessarily the right strategy for your task)
```python
{example_reducer_code}
```

**What to learn from the example**:
- Function signature and interface
- Multi-stage reduction approach
- How to use test_fn() to validate each candidate
- Progress output with [ReduceFix] prefix
- Tracking metrics (tests, time, size)

---

Now, generate a format-aware reducer for **{target_name}**:

# Target project: {target_name}
# Expected format type: {format_desc}
{format_section}

## Implementation guidelines (format-specific hints):
{guidance}

## Requirements:
1. **Format awareness**: Use the actual file analysis above, don't just do generic block/line reduction
2. **Multi-stage**: Design stages appropriate for THIS format (not just copying example)
3. **Generality**: Works for all {target_name} test cases, not just this one
4. **Progress output**: [ReduceFix] prefix, show stage progress, test counts, timing
5. **Function signature**: `def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:`

## Critical Python syntax rules:
⚠️  **f-string limitation**: Cannot use backslash inside curly brace expressions
- WRONG: Using join with newline directly inside f-string braces
- CORRECT: Calculate the joined string first, assign to variable, then use in f-string
- Always do string operations BEFORE f-string formatting, not inside the braces

Please generate complete implementation. Output ONLY the Python code block, no explanations.
"""
    else:
        # Zero-shot mode (no example)
        format_section = ""
        if format_info:
            format_section = f"""

## Actual Test Case Analysis:
{format_info}

**Your task is to THINK and DESIGN**:
1. Analyze the format information above carefully
2. Determine the file structure (text vs binary, structured vs unstructured)
3. Identify natural "reduction units" specific to this format
4. Design a multi-stage reduction strategy (coarse to fine granularity)
5. Implement format-aware reduction, NOT just generic block/line deletion

**Format-specific strategy examples** (as inspiration, not templates):

| If format is... | Consider these strategies |
|-----------------|---------------------------|
| XML/HTML | Match `<tag>...</tag>` pairs → remove elements → remove attributes → reduce text content |
| PDF | Find `obj...endobj` blocks → remove objects → reduce stream content → prune dictionaries |
| JSON | Parse `{...}` and `[...]` → remove objects/arrays → remove keys → reduce values |
| Images | Identify file signature → preserve header → reduce metadata chunks → reduce pixel data |
| Fonts | Parse table directory → remove non-essential tables → reduce glyph data |
| Source code | Find function/class boundaries → remove functions → remove statements → simplify |
| Plain text | Split by paragraphs → remove paragraphs → remove lines → reduce line content |
| Binary (unknown) | Fixed-size blocks → byte-level reduction |

**Critical**: These are EXAMPLES to show the thinking process. Your actual strategy must be based
on the SPECIFIC format analysis provided above!
"""
        
        user_prompt = f"""Generate a format-aware reducer for the {target_name} project:

# Target project: {target_name}
# Expected format type: {format_desc}
{format_section}

## Implementation guidelines (format-specific hints):
{guidance}

## Requirements:
1. **Format awareness**: Design stages based on the ACTUAL file analysis provided above
2. **Multi-stage strategy**: Implement multiple reduction stages from coarse to fine
3. **Generality**: Must work for all {target_name} test cases, not just this specific one
4. **Validation**: Use test_fn(candidate) to check if bug still reproduces
5. **Progress output**: 
   - Use [ReduceFix] prefix for all output
   - Show stage start/completion
   - Report progress every 10-50 tests
   - Final summary: tests, time, reduction rate
6. **Function signature**: 
   ```python
   def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
   ```

## Critical Python syntax rules:
⚠️  **f-string limitation**: CANNOT use backslash inside curly brace expressions
- WRONG: Putting string join with newline directly inside f-string braces
- CORRECT: First calculate joined = lines_join(lines), then use joined in f-string
- Always calculate string operations BEFORE f-string formatting, not inside braces

**Critical thinking required**: 
- Don't just implement generic block/line reduction
- Actually parse or pattern-match the format structure
- Design stages that respect the format's natural boundaries
- Balance between format correctness and aggressive reduction

Output ONLY the complete Python code block. No explanations or markdown outside the code.
"""
    
    return [
        {"role": "system", "content": system_prompt},
        {"role": "user", "content": user_prompt}
    ]


def extract_file_format_info(case: Dict[str, str]) -> str:
    """Extract file format information with intelligent analysis
    
    Provides comprehensive format analysis to help LLM infer optimal reduction strategy
    """
    data_dir = case.get('data_dir')
    if not data_dir:
        return "Format information unavailable"
    
    testcase_path = os.path.join(data_dir, 'testcase')
    if not os.path.exists(testcase_path):
        return "Test file not found"
    
    try:
        import subprocess
        
        # 1. 使用 file 命令识别文件类型
        file_result = subprocess.run(
            ['file', testcase_path],
            capture_output=True,
            text=True,
            timeout=5
        )
        file_type = file_result.stdout.strip() if file_result.returncode == 0 else "Unknown"
        
        # 2. 读取完整文件
        with open(testcase_path, 'rb') as f:
            full_data = f.read()
        
        file_size = len(full_data)
        
        # 3. 转换文件头和尾为 hex dump
        header = full_data[:512]
        hex_lines_head = []
        for i in range(0, min(len(header), 256), 16):
            chunk = header[i:i+16]
            hex_part = ' '.join(f'{b:02x}' for b in chunk)
            ascii_part = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
            hex_lines_head.append(f"{i:08x}  {hex_part:<48}  |{ascii_part}|")
        
        hex_dump_head = '\n'.join(hex_lines_head)
        
        # 文件尾部 hex dump（最后 256 bytes）
        hex_dump_tail = ""
        if file_size > 512:  # 只有足够大的文件才显示尾部
            tail = full_data[-512:]
            tail_start_offset = max(0, file_size - 512)
            hex_lines_tail = []
            for i in range(max(0, len(tail) - 256), len(tail), 16):
                chunk = tail[i:i+16]
                hex_part = ' '.join(f'{b:02x}' for b in chunk)
                ascii_part = ''.join(chr(b) if 32 <= b < 127 else '.' for b in chunk)
                offset = tail_start_offset + i
                hex_lines_tail.append(f"{offset:08x}  {hex_part:<48}  |{ascii_part}|")
            hex_dump_tail = '\n'.join(hex_lines_tail)
        
        # 4. 智能格式分析
        analysis_points = []
        sample_content_lines = []  # 用于存储实际内容样本
        
        # 检查是否是文本文件
        try:
            text_content = full_data.decode('utf-8', errors='strict')
            is_text = True
            analysis_points.append("✓ TEXT FILE (valid UTF-8 encoding)")
            
            # 文本文件的详细分析
            lines = text_content.split('\n')
            analysis_points.append(f"  - Total lines: {len(lines)}")
            analysis_points.append(f"  - Average line length: {sum(len(l) for l in lines) / max(len(lines), 1):.1f} chars")
            
            # 提取内容样本（前几行 + 后几行，去除空行）
            non_empty_lines_head = [l.strip() for l in lines[:20] if l.strip()]
            non_empty_lines_tail = [l.strip() for l in lines[-20:] if l.strip()]
            
            if non_empty_lines_head:
                sample_content_lines.append("\n📄 Content sample (HEAD - first few lines):")
                for i, line in enumerate(non_empty_lines_head[:5], 1):
                    preview = line[:100] + ('...' if len(line) > 100 else '')
                    sample_content_lines.append(f"  Line {i}: {preview}")
            
            if non_empty_lines_tail and len(lines) > 10:
                sample_content_lines.append("\n📄 Content sample (TAIL - last few lines):")
                for i, line in enumerate(non_empty_lines_tail[-5:], 1):
                    preview = line[:100] + ('...' if len(line) > 100 else '')
                    sample_content_lines.append(f"  Line -{6-i}: {preview}")
            
            # 格式推断（基于内容特征）
            import re
            
            # 检查 XML/HTML
            if text_content.strip().startswith('<?xml') or text_content.strip().startswith('<'):
                elements = re.findall(r'<([a-zA-Z_][\w:.-]*)', text_content)
                unique_tags = set(elements)
                opening_tags = re.findall(r'<([a-zA-Z_][\w:.-]*)[^/>]*>', text_content)
                closing_tags = re.findall(r'</([a-zA-Z_][\w:.-]*)>', text_content)
                
                analysis_points.append(f"\n  🔍 Format: XML/HTML")
                analysis_points.append(f"    - Total tag occurrences: {len(elements)}")
                analysis_points.append(f"    - Unique tag names: {len(unique_tags)}")
                analysis_points.append(f"    - Opening tags: {len(opening_tags)}")
                analysis_points.append(f"    - Closing tags: {len(closing_tags)}")
                analysis_points.append(f"    - Well-formed: {'likely yes' if abs(len(opening_tags) - len(closing_tags)) <= 1 else 'possibly not'}")
                
                if len(unique_tags) <= 15:
                    analysis_points.append(f"    - Tag names: {', '.join(sorted(unique_tags))}")
                
                # 检查属性
                attrs = re.findall(r'\s+[\w:.-]+\s*=\s*["\'][^"\']*["\']', text_content[:1000])
                if attrs:
                    analysis_points.append(f"    - Attributes found: {len(attrs)} (in first 1000 chars)")
                
                # 检查根元素闭合（查看开头和结尾）
                head_match = re.search(r'<([a-zA-Z_][\w:.-]*)', text_content[:200])
                tail_match = re.search(r'</([a-zA-Z_][\w:.-]*)>\s*$', text_content[-200:])
                if head_match and tail_match:
                    root_open = head_match.group(1)
                    root_close = tail_match.group(1)
                    analysis_points.append(f"    - Root element: <{root_open}> ... </{root_close}> (matched: {root_open == root_close})")
            
            # 检查 JSON
            elif text_content.strip().startswith('{') or text_content.strip().startswith('['):
                brace_count = text_content.count('{')
                bracket_count = text_content.count('[')
                quote_count = text_content.count('"')
                
                analysis_points.append(f"\n  🔍 Format: Likely JSON")
                analysis_points.append(f"    - Objects ({{}}): {brace_count}")
                analysis_points.append(f"    - Arrays ([]): {bracket_count}")
                analysis_points.append(f"    - String quotes: {quote_count}")
                
                # 检查顶层结构闭合
                starts_with_brace = text_content.strip().startswith('{')
                ends_with_brace = text_content.strip().endswith('}')
                starts_with_bracket = text_content.strip().startswith('[')
                ends_with_bracket = text_content.strip().endswith(']')
                
                if starts_with_brace and ends_with_brace:
                    analysis_points.append(f"    - Top-level: Object {{ ... }} (properly closed)")
                elif starts_with_bracket and ends_with_bracket:
                    analysis_points.append(f"    - Top-level: Array [ ... ] (properly closed)")
                
                # 尝试找到顶层键
                keys = re.findall(r'"([^"]+)"\s*:', text_content[:500])
                if keys:
                    analysis_points.append(f"    - Sample keys: {', '.join(keys[:5])}")
            
            # 检查 PDF (text representation)
            elif '%PDF' in text_content[:100]:
                obj_count = text_content.count(' obj')
                endobj_count = text_content.count('endobj')
                stream_count = text_content.count('stream')
                endstream_count = text_content.count('endstream')
                
                analysis_points.append(f"\n  🔍 Format: PDF (text-based or partially)")
                analysis_points.append(f"    - Objects: {obj_count} (endobj: {endobj_count})")
                analysis_points.append(f"    - Streams: {stream_count} (endstream: {endstream_count})")
                
                # 检查常见PDF对象类型
                catalog_count = text_content.count('/Catalog')
                pages_count = text_content.count('/Pages')
                page_count = text_content.count('/Page')
                analysis_points.append(f"    - /Catalog: {catalog_count}, /Pages: {pages_count}, /Page: {page_count}")
                
                # 检查PDF尾部结构
                tail_text = text_content[-500:]
                has_trailer = 'trailer' in tail_text
                has_xref = 'xref' in tail_text or 'startxref' in tail_text
                has_eof = '%%EOF' in tail_text
                analysis_points.append(f"    - Tail structure: trailer={has_trailer}, xref={has_xref}, %%EOF={has_eof}")
            
            # 检查源代码
            elif '<?php' in text_content or 'function ' in text_content or 'class ' in text_content:
                func_count = len(re.findall(r'\bfunction\s+\w+', text_content))
                class_count = len(re.findall(r'\bclass\s+\w+', text_content))
                
                analysis_points.append(f"\n  🔍 Format: Source code")
                if '<?php' in text_content:
                    analysis_points.append(f"    - Language: PHP")
                analysis_points.append(f"    - Functions: {func_count}")
                analysis_points.append(f"    - Classes: {class_count}")
            
            # 普通文本
            else:
                analysis_points.append(f"\n  🔍 Format: Plain text (no specific structure detected)")
            
        except UnicodeDecodeError:
            is_text = False
            analysis_points.append("✓ BINARY FILE (not valid UTF-8)")
            
            # 二进制文件分析
            # 检查常见的二进制格式签名
            signature_found = False
            
            # 检查 fuzzer 签名（优先级最高）
            fuzzer_signatures = [b'UZZ-T', b'UZZG', b'FUZZ', b'libFuzzer']
            found_fuzzer_sigs = []
            for sig in fuzzer_signatures:
                if sig in full_data:
                    idx = full_data.rfind(sig)
                    found_fuzzer_sigs.append(f"{sig.decode('utf-8', errors='ignore')} at offset {idx}")
            
            if found_fuzzer_sigs:
                analysis_points.append("\n  🔍 Format: **FUZZER-GENERATED TEST CASE** (likely minimal trigger)")
                signature_found = True
                analysis_points.append(f"    - Fuzzer signatures found: {', '.join(found_fuzzer_sigs)}")
                
                # 统计特征字节
                special_bytes = {
                    0x00: full_data.count(b'\x00'),
                    0x20: full_data.count(b' '),
                    0x60: full_data.count(b'`'),
                    0x7b: full_data.count(b'{'),
                    0xf9: full_data.count(b'\xf9'),
                    0xff: full_data.count(b'\xff'),
                }
                analysis_points.append(f"    - Byte frequency:")
                for byte_val, count in sorted(special_bytes.items(), key=lambda x: -x[1]):
                    if count > file_size * 0.05:  # >5% of file
                        ratio = count / file_size * 100
                        analysis_points.append(f"      • 0x{byte_val:02x}: {count} occurrences ({ratio:.1f}%)")
                
                # 检测长重复字节序列
                max_run = 0
                max_run_byte = None
                for byte_val in [0x00, 0x20, 0x60, 0x7b, 0xf9, 0xff]:
                    pattern = bytes([byte_val])
                    current_run = 0
                    for i in range(len(full_data)):
                        if full_data[i:i+1] == pattern:
                            current_run += 1
                            if current_run > max_run:
                                max_run = current_run
                                max_run_byte = byte_val
                        else:
                            current_run = 0
                
                if max_run > 10:
                    analysis_points.append(f"    - Longest byte run: {max_run} × 0x{max_run_byte:02x}")
                
                analysis_points.append(f"\n    ⚠️  **CRITICAL STRATEGY FOR FUZZER INPUTS**:")
                analysis_points.append(f"    - This is likely a MINIMAL test case already highly optimized by fuzzer")
                analysis_points.append(f"    - Traditional 'format-aware' reduction may NOT work well")
                analysis_points.append(f"    - Bug triggered by SPECIFIC BYTE SEQUENCES at SPECIFIC OFFSETS")
                analysis_points.append(f"    - Recommended: AGGRESSIVE DDMin with adaptive chunk sizing")
                analysis_points.append(f"    - File size {file_size} bytes → Start with {min(256, file_size//8)}-byte chunks, then halve repeatedly")
            
            # 特殊处理：小型结构化二进制消息 (<512 bytes)
            elif file_size < 512:
                analysis_points.append("\n  🔍 Format: Small binary message (likely network protocol/structured packet)")
                signature_found = True
                
                # 统计填充字节
                padding_bytes = sum(1 for b in full_data if b in (0x00, 0x20, 0xFF))
                padding_ratio = padding_bytes / len(full_data) * 100
                analysis_points.append(f"    - Padding bytes (0x00/0x20/0xFF): {padding_ratio:.1f}%")
                
                # 检查是否有长度字段的特征（前几个字节中有小整数）
                if len(header) >= 4:
                    import struct
                    try:
                        # 尝试读取前几个字节作为长度字段
                        potential_lengths = [
                            struct.unpack('>H', header[0:2])[0],  # Big-endian 16-bit
                            struct.unpack('<H', header[0:2])[0],  # Little-endian 16-bit
                            struct.unpack('>I', header[0:4])[0],  # Big-endian 32-bit
                        ]
                        reasonable_lengths = [l for l in potential_lengths if 0 < l < file_size * 2]
                        if reasonable_lengths:
                            analysis_points.append(f"    - Possible length fields detected: {reasonable_lengths[:3]}")
                    except:
                        pass
                
                analysis_points.append(f"    - Reduction strategy: **BYTE-LEVEL DDMin** (critical for small files)")
                analysis_points.append(f"    - Warning: DO NOT use 256-byte chunks (will cause infinite loop)")
            
            elif header[:4] == b'%PDF':
                analysis_points.append("\n  🔍 Format: PDF (binary)")
                signature_found = True
                # 在二进制中查找文本线索
                try:
                    partial_text = full_data.decode('utf-8', errors='ignore')
                    obj_count = partial_text.count(' obj')
                    if obj_count > 0:
                        analysis_points.append(f"    - Objects detected: ~{obj_count}")
                except:
                    pass
            
            elif header[:4] == b'\x89PNG':
                analysis_points.append("\n  🔍 Format: PNG image")
                signature_found = True
                # PNG chunk structure
                chunk_count = full_data.count(b'IDAT') + full_data.count(b'IHDR')
                analysis_points.append(f"    - PNG chunks detected: ~{chunk_count}")
            
            elif header[:2] == b'\xff\xd8':
                analysis_points.append("\n  🔍 Format: JPEG image")
                signature_found = True
                # JPEG markers
                marker_count = full_data.count(b'\xff')
                analysis_points.append(f"    - JPEG markers: ~{marker_count}")
            
            elif header[:4] == b'GIF8':
                analysis_points.append("\n  🔍 Format: GIF image")
                signature_found = True
            
            elif b'true' in header[:12].lower() or b'OTTO' in header[:12]:
                analysis_points.append("\n  🔍 Format: Font file (TrueType/OpenType)")
                signature_found = True
                # 尝试解析表数量
                if len(header) >= 12:
                    import struct
                    try:
                        num_tables = struct.unpack('>H', header[4:6])[0]
                        analysis_points.append(f"    - Number of tables: {num_tables}")
                    except:
                        pass
            
            if not signature_found:
                analysis_points.append("\n  🔍 Format: Unknown binary")
            
            # 统计可打印字符比例
            printable = sum(1 for b in full_data if 32 <= b < 127 or b in (9, 10, 13))
            printable_ratio = printable / len(full_data) * 100
            analysis_points.append(f"    - Printable character ratio: {printable_ratio:.1f}%")
            
            if printable_ratio > 50:
                analysis_points.append(f"    - Mixed text/binary (high printable ratio)")
            elif printable_ratio < 10:
                analysis_points.append(f"    - Pure binary (low printable ratio)")
        
        # 5. 结构特征分析
        analysis_points.append("\nStructural characteristics:")
        
        # 换行符统计
        newline_count = full_data.count(b'\n')
        if newline_count > 10:
            analysis_points.append(f"  - Contains {newline_count} newlines (line-based structure possible)")
        else:
            analysis_points.append(f"  - Few newlines ({newline_count}) - likely binary or compact format")
        
        # 重复模式检测
        if file_size > 1024:
            sample_block = full_data[:1024]
            if sample_block.count(b'\x00') > 512:
                analysis_points.append(f"  - High null byte density - sparse binary data")
        
        analysis_text = '\n'.join(analysis_points)
        sample_text = '\n'.join(sample_content_lines) if sample_content_lines else ""
        
        # 构建尾部信息（如果有）
        tail_section = ""
        if hex_dump_tail:
            tail_section = f"""
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
🔧 FILE TAIL (last 256 bytes in hexadecimal)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
{hex_dump_tail}
"""
        
        format_info = f"""File type (from 'file' command): {file_type}
File size: {file_size} bytes ({file_size/1024:.1f} KB)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📊 INTELLIGENT FORMAT ANALYSIS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

{analysis_text}
{sample_text}

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
🔧 FILE HEADER (first 256 bytes in hexadecimal)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
{hex_dump_head}
{tail_section}
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
💡 YOUR TASK
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Based on the analysis above (including both HEAD and TAIL):
1. Identify the format type (XML, PDF, JSON, image, font, source code, plain text, binary)
2. Determine text vs binary nature and overall structure
3. Identify natural "reduction units" for this specific format
4. Note structural patterns at both beginning and end (e.g., XML root tags, PDF trailer)
5. Design a multi-stage reduction strategy exploiting format structure
6. Implement using format-specific patterns (regex, delimiters, structure markers)

⚠️  CRITICAL: This reducer must be GENERIC - it will be used for ALL test cases
of this target, not just this one file. Use the format analysis to guide your 
design, but ensure the strategy generalizes to similar files.
"""
        return format_info
    
    except Exception as e:
        return f"Unable to extract format information: {e}"


def build_reducer(case_id: str, model: str, model_tag: str) -> str:
    """构建 reducer（主流程）
    
    按 target 分组生成 reducer，而不是按 case_id。
    同一个 target 的所有案例共用一个 reducer。
    """
    
    # 1. 解析目标案例，获取 target
    case = resolve_case(case_id)
    if not case:
        raise SystemExit(f"[Error] 无法解析 case_id={case_id}，请配置 oss_fuzz/cases.json 或环境变量。")
    
    target = case.get('target', 'unknown')
    print(f"[Info] 目标案例: {case_id}")
    print(f"[Info] Target: {target}")
    
    # 1.5 提取文件格式信息
    print(f"[Info] 分析文件格式...")
    format_info = extract_file_format_info(case)
    print(f"[Info] 格式信息已提取")
    
    # 2. 设置输出目录 - 优先使用 cases_data，备份到 artifacts
    base = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    
    # 优先使用 cases_data 目录
    cases_data_dir = os.path.join(base, "oss_fuzz_results", "cases_data", target, model_tag)
    artifacts_dir = os.path.join(base, "oss_fuzz_results", "artifacts", target, model_tag)
    
    # 优先从 cases_data 查找，如果不存在则从 artifacts 查找
    for base_dir in [cases_data_dir, artifacts_dir]:
        if not os.path.exists(base_dir):
            continue
        
        model_specific_path = os.path.join(base_dir, f"reducer_{model}.py")
        standard_path = os.path.join(base_dir, TARGET_FILENAME)
        
        if os.path.exists(model_specific_path):
            print(f"[Info] 找到已存在的 model-specific reducer: {model_specific_path}")
            # 确保 cases_data 也有副本
            if base_dir != cases_data_dir:
                os.makedirs(cases_data_dir, exist_ok=True)
                dest_path = os.path.join(cases_data_dir, TARGET_FILENAME)
                import shutil
                shutil.copy2(model_specific_path, dest_path)
                print(f"[Info] 已复制到 cases_data: {dest_path}")
                return dest_path
            else:
                import shutil
                dest_standard = os.path.join(base_dir, TARGET_FILENAME)
                shutil.copy2(model_specific_path, dest_standard)
                return dest_standard
        
        if os.path.exists(standard_path):
            print(f"[Info] 找到已存在的 standard reducer: {standard_path}")
            # 确保 cases_data 也有副本
            if base_dir != cases_data_dir:
                os.makedirs(cases_data_dir, exist_ok=True)
                dest_path = os.path.join(cases_data_dir, TARGET_FILENAME)
                import shutil
                shutil.copy2(standard_path, dest_path)
                print(f"[Info] 已复制到 cases_data: {dest_path}")
                return dest_path
            else:
                return standard_path
    
    # 如果都不存在，则使用 cases_data 作为输出目录
    art_dir = cases_data_dir
    os.makedirs(art_dir, exist_ok=True)
    print(f"[Info] Reducer 输出目录: {art_dir}")
    
    standard_path = os.path.join(art_dir, TARGET_FILENAME)
    
    # 4. 读取示例 reducer（用于 one-shot）
    example_case = None
    example_code = None
    # 总是使用示例（因为现在按 target 分组，不会与示例冲突）
    example_case = resolve_case(EXAMPLE_CASE_ID)
    example_code = read_example_reducer(EXAMPLE_CASE_ID)
    
    # 5. 构建 prompt（为整个 target 生成，包含格式信息）
    print(f"[Info] 为 {target} 构建通用 reducer prompt...")
    prompt_history = build_generation_prompt(
        target_name=target,
        example_case=example_case,
        example_reducer_code=example_code,
        format_info=format_info
    )
    
    # 6. 保存 prompt（使用统一命名）
    prompt_filename = f"llm_prompt_{model_tag}.txt"
    prompt_path = os.path.join(art_dir, prompt_filename)
    try:
        full_prompt_text = f"SYSTEM:\n{prompt_history[0]['content']}\n\nUSER:\n{prompt_history[1]['content']}"
        with open(prompt_path, 'w', encoding='utf-8') as f:
            f.write(full_prompt_text)
        print(f"[Info] Prompt 已保存: {prompt_path}")
    except Exception as e:
        print(f"[Warning] 保存 prompt 失败: {e}", file=sys.stderr)
    
    # 7. 调用 LLM 生成代码
    print(f"[Info] 使用模型 {model} 生成 reducer...")
    try:
        raw_response = llm.call_llm(
            prompt_history=prompt_history,
            model_name=model,
            temperature=LLM_TEMPERATURE,
            max_tokens=LLM_MAX_TOKENS
        )
    except Exception as e:
        print(f"[Error] LLM 调用失败: {e}", file=sys.stderr)
        traceback.print_exc()
        raw_response = None
    
    # 8. 保存原始响应（使用统一命名）
    response_filename = f"llm_response_raw_{model_tag}.txt"
    response_path = os.path.join(art_dir, response_filename)
    if raw_response:
        try:
            with open(response_path, 'w', encoding='utf-8') as f:
                f.write(raw_response)
            print(f"[Info] 原始响应已保存: {response_path}")
        except Exception as e:
            print(f"[Warning] 保存响应失败: {e}", file=sys.stderr)
    
    # 9. 提取代码
    extracted_code = None
    if raw_response:
        extracted_code = llm.extract_python_code(raw_response)
        if extracted_code:
            print(f"[Info] 成功提取代码 ({len(extracted_code)} 字符)")
        else:
            print(f"[Warning] 无法从响应中提取 Python 代码", file=sys.stderr)
    
    # 10. 保存生成的 reducer（或 fallback）
    if extracted_code:
        code_to_save = extracted_code
        print(f"[Info] 使用 LLM 生成的代码")
    else:
        # Fallback: Use simple default implementation (with detailed progress output)
        print(f"[Warning] LLM generation failed, using fallback reducer")
        code_to_save = """# Fallback reducer (LLM generation failed)
import time

def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    \"\"\"Fallback reducer using simple block-level strategy with detailed progress\"\"\"
    if not input_bytes or not test_fn(input_bytes):
        return input_bytes
    
    data = input_bytes
    original_size = len(data)
    test_count = 0
    start_time = time.time()
    
    if verbose:
        print(f"[ReduceFix] Starting reduction (Fallback strategy)")
        print(f"[ReduceFix] Original size: {original_size} bytes")
    
    # Stage 1: Block-level greedy removal
    if verbose:
        print(f"[ReduceFix] Stage 1: Block-level greedy removal")
    
    block_size = 2048
    blocks = [data[i:i+block_size] for i in range(0, len(data), block_size)]
    
    if verbose:
        print(f"[ReduceFix] Split into {len(blocks)} blocks ({block_size} bytes each)")
    
    i = 0
    while i < len(blocks):
        candidate = b"".join(blocks[:i] + blocks[i+1:])
        if candidate:
            test_count += 1
            if verbose and test_count % 10 == 0:
                current_size = len(b"".join(blocks))
                elapsed = time.time() - start_time
                print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(blocks)} blocks, {current_size} bytes, elapsed={elapsed:.1f}s")
            
            if test_fn(candidate):
                blocks.pop(i)
                if verbose:
                    new_size = len(candidate)
                    print(f"  [ReduceFix] ✓ Successfully removed block {i} ({len(blocks)+1} → {len(blocks)} blocks), {new_size} bytes")
            else:
                i += 1
        else:
            i += 1
    
    data = b"".join(blocks)
    stage1_size = len(data)
    
    if verbose:
        reduction = (1 - stage1_size / original_size) * 100
        print(f"[ReduceFix] Stage 1 complete: {original_size} → {stage1_size} bytes ({reduction:.1f}% reduction)")
    
    # Stage 2: Line-level fine tuning
    if b"\\n" in data:
        if verbose:
            print(f"[ReduceFix] Stage 2: Line-level fine tuning")
        
        lines = data.splitlines(keepends=True)
        if verbose:
            print(f"[ReduceFix] Split into {len(lines)} lines")
        
        j = 0
        while len(lines) > 1 and j < len(lines):
            candidate = b"".join(lines[:j] + lines[j+1:])
            if candidate:
                test_count += 1
                if verbose and test_count % 50 == 0:
                    current_size = len(b"".join(lines))
                    elapsed = time.time() - start_time
                    print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(lines)} lines, {current_size} bytes, elapsed={elapsed:.1f}s")
                
                if test_fn(candidate):
                    lines.pop(j)
                    if verbose and len(lines) % 50 == 0:
                        print(f"  [ReduceFix] Current remaining: {len(lines)} lines")
                else:
                    j += 1
            else:
                j += 1
        
        data = b"".join(lines)
    
    final_size = len(data)
    elapsed = time.time() - start_time
    
    if verbose:
        reduction = (1 - final_size / original_size) * 100
        print(f"[ReduceFix] Complete: {original_size} → {final_size} bytes ({reduction:.1f}% reduction)")
        print(f"[ReduceFix] Total tests: {test_count}, total time: {elapsed:.1f}s")
    
    return data
"""
    
    # 11. 保存文件
    try:
        with open(standard_path, 'w', encoding='utf-8') as f:
            f.write(code_to_save)
        print(f"[Success] Reducer 已保存: {standard_path}")
        
        # 同时保存带模型标签的备份
        import shutil
        backup_filename = f"reducer_{model_tag}.py"
        backup_path = os.path.join(art_dir, backup_filename)
        shutil.copy2(standard_path, backup_path)
        print(f"[Info] 备份副本: {backup_path}")
        
        return standard_path
    
    except Exception as e:
        print(f"[Error] 保存 reducer 失败: {e}", file=sys.stderr)
        raise


def main():
    parser = argparse.ArgumentParser(
        description="Generate OSS-Fuzz reducer using one-shot LLM prompt"
    )
    parser.add_argument("case_id", help="案例 ID (如 benchmark-01, pdfium)")
    parser.add_argument("--model", default="qwen-plus", help="LLM 模型名称")
    parser.add_argument("--tag", required=True, help="模型标签（用于文件命名）")
    args = parser.parse_args()
    
    try:
        path = build_reducer(args.case_id, args.model, args.tag)
        # 只输出路径到 stdout（供 shell 脚本捕获）
        sys.stdout.write(path + "\n")
    except Exception as e:
        print(f"[Error] 构建失败: {e}", file=sys.stderr)
        traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main()



