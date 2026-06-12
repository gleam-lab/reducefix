#!/usr/bin/env python3
"""Prepare objective SQLancer SQLite manifests for the DBMS main experiment."""

from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import subprocess
import urllib.request
from collections import Counter
from pathlib import Path
from typing import Any


BUGS_JSON_URL = "https://raw.githubusercontent.com/sqlancer/bugs/master/bugs.json"
DEFAULT_FORBID_PATTERNS = ["no such table", "no such column", "syntax error", "parse error"]
DEPENDENCY_ERROR_PATTERNS = ["no such table", "no such column"]


def slugify(text: str, max_len: int = 64) -> str:
    chars = []
    for ch in text.lower():
        if ch.isalnum():
            chars.append(ch)
        elif chars and chars[-1] != "_":
            chars.append("_")
    return ("".join(chars).strip("_") or "case")[:max_len].strip("_")


def strip_line_comment(line: str) -> str:
    quote: str | None = None
    i = 0
    while i < len(line):
        ch = line[i]
        nxt = line[i + 1] if i + 1 < len(line) else ""
        if quote:
            if ch == quote:
                if i + 1 < len(line) and line[i + 1] == quote:
                    i += 2
                    continue
                quote = None
            i += 1
            continue
        if ch in ("'", '"', "`"):
            quote = ch
            i += 1
            continue
        if ch == "-" and nxt == "-":
            return line[:i].rstrip()
        i += 1
    return line.rstrip()


def normalize_test_sql(test: list[str]) -> str:
    lines = []
    for line in test:
        cleaned = strip_line_comment(line)
        if cleaned.strip():
            lines.append(cleaned)
    return "\n".join(lines) + "\n"


def load_bugs(path: str | None) -> tuple[list[dict[str, Any]], bytes]:
    if path:
        raw = Path(path).read_bytes()
    else:
        with urllib.request.urlopen(BUGS_JSON_URL, timeout=60) as response:
            raw = response.read()
    return json.loads(raw.decode("utf-8")), raw


def run_sqlite(sql: str, timeout_sec: float) -> dict[str, Any]:
    sqlite = shutil.which("sqlite3")
    if not sqlite:
        raise RuntimeError("sqlite3 binary not found on PATH")
    try:
        proc = subprocess.run(
            [sqlite, "-batch", "-noheader"],
            input=sql.encode("utf-8"),
            capture_output=True,
            timeout=timeout_sec,
            check=False,
        )
        return {
            "returncode": proc.returncode,
            "stdout": proc.stdout.decode("utf-8", errors="replace"),
            "stderr": proc.stderr.decode("utf-8", errors="replace"),
            "timeout": False,
        }
    except subprocess.TimeoutExpired as exc:
        stdout = exc.stdout.decode("utf-8", errors="replace") if isinstance(exc.stdout, bytes) else (exc.stdout or "")
        stderr = exc.stderr.decode("utf-8", errors="replace") if isinstance(exc.stderr, bytes) else (exc.stderr or "")
        return {
            "returncode": 124,
            "stdout": stdout,
            "stderr": stderr,
            "timeout": True,
        }


def observable(result: dict[str, Any]) -> bool:
    return bool(result["timeout"] or result["returncode"] != 0 or result["stdout"].strip() or result["stderr"].strip())


def stable(results: list[dict[str, Any]]) -> bool:
    if not results:
        return False
    first = results[0]
    return all(
        item["returncode"] == first["returncode"]
        and item["stdout"] == first["stdout"]
        and item["stderr"] == first["stderr"]
        and item["timeout"] == first["timeout"]
        for item in results[1:]
    )


def choose_stderr_signature(stderr: str) -> str:
    candidates = [
        "SQL logic error",
        "database disk image is malformed",
        "constraint failed",
        "UNIQUE constraint failed",
        "FOREIGN KEY constraint failed",
        "malformed database schema",
        "database table is locked",
        "integer overflow",
    ]
    for candidate in candidates:
        if candidate.lower() in stderr.lower():
            return candidate
    first_line = next((line.strip() for line in stderr.splitlines() if line.strip()), "")
    return first_line[:120]


def build_oracle(result: dict[str, Any]) -> dict[str, Any]:
    oracle: dict[str, Any] = {"exit_code": result["returncode"]}
    if result["timeout"]:
        oracle["timeout"] = True
    stdout = result["stdout"]
    stderr = result["stderr"]
    if stdout:
        oracle["stdout_equals"] = stdout
    if stderr:
        signature = choose_stderr_signature(stderr)
        if signature:
            oracle["stderr_contains"] = signature
        forbidden = []
        lowered = stderr.lower()
        for pattern in DEPENDENCY_ERROR_PATTERNS:
            if pattern not in lowered:
                forbidden.append(pattern)
        if forbidden:
            oracle["forbid_stderr_contains"] = forbidden
    else:
        oracle["forbid_stderr_contains"] = DEFAULT_FORBID_PATTERNS
    return oracle


def write_jsonl(path: Path, rows: list[dict[str, Any]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as handle:
        for row in rows:
            handle.write(json.dumps(row, ensure_ascii=False, sort_keys=True) + "\n")


def summarize(rows: list[dict[str, Any]], selected: list[dict[str, Any]], source_sha256: str, sqlite_version: str) -> dict[str, Any]:
    return {
        "source": BUGS_JSON_URL,
        "source_sha256": source_sha256,
        "sqlite_version": sqlite_version,
        "total_sqlancer_bugs": len(rows),
        "sqlite_with_test": sum(1 for row in rows if row["dbms"] == "SQLite" and row["has_test"]),
        "sqlite_observable": sum(1 for row in rows if row["dbms"] == "SQLite" and row["observable"]),
        "sqlite_stable_observable": sum(1 for row in rows if row["dbms"] == "SQLite" and row["stable_observable"]),
        "selected_count": len(selected),
        "selection_rule": "dbms=SQLite; status=fixed; normalized SQL >= min_bytes; statements >= min_statements; stable observable on current sqlite3",
        "selected_by_oracle": dict(Counter(row["sqlancer_oracle"] for row in selected)),
        "selected_by_status": dict(Counter(row["status"] for row in selected)),
        "selected_bytes": {
            "min": min((row["normalized_bytes"] for row in selected), default=0),
            "max": max((row["normalized_bytes"] for row in selected), default=0),
            "avg": sum(row["normalized_bytes"] for row in selected) / len(selected) if selected else 0.0,
        },
        "selected_statements": {
            "min": min((row["normalized_statements"] for row in selected), default=0),
            "max": max((row["normalized_statements"] for row in selected), default=0),
            "avg": sum(row["normalized_statements"] for row in selected) / len(selected) if selected else 0.0,
        },
    }


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Prepare SQLancer SQLite main-experiment data.")
    parser.add_argument("--bugs-json", default=None, help="Optional local SQLancer bugs.json path.")
    parser.add_argument("--cases-dir", default="dbms_results/cases/sqlancer_sqlite_main")
    parser.add_argument("--candidate-index", default="dbms_results/manifests/sqlancer_sqlite_candidate_index.jsonl")
    parser.add_argument("--all-observable-manifest", default="dbms_results/manifests/sqlancer_sqlite_fixed_observable_all.jsonl")
    parser.add_argument("--main-manifest", default="dbms_results/manifests/sqlancer_sqlite_main_current.jsonl")
    parser.add_argument("--summary", default="dbms_results/manifests/sqlancer_sqlite_main_current_summary.json")
    parser.add_argument("--min-bytes", type=int, default=100)
    parser.add_argument("--min-statements", type=int, default=3)
    parser.add_argument("--repetitions", type=int, default=3)
    parser.add_argument("--timeout-sec", type=float, default=5.0)
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    bugs, raw = load_bugs(args.bugs_json)
    source_sha256 = hashlib.sha256(raw).hexdigest()
    sqlite_version = subprocess.run(["sqlite3", "-version"], text=True, capture_output=True, check=False).stdout.strip()

    cases_dir = Path(args.cases_dir)
    cases_dir.mkdir(parents=True, exist_ok=True)

    candidate_rows: list[dict[str, Any]] = []
    manifest_rows_all: list[dict[str, Any]] = []
    manifest_rows_main: list[dict[str, Any]] = []

    for index, bug in enumerate(bugs):
        dbms = bug.get("dbms")
        test = bug.get("test")
        has_test = isinstance(test, list) and bool(test)
        base_row: dict[str, Any] = {
            "source": BUGS_JSON_URL,
            "source_index": index,
            "dbms": dbms,
            "title": bug.get("title"),
            "date": bug.get("date"),
            "status": bug.get("status"),
            "sqlancer_oracle": bug.get("oracle"),
            "has_test": has_test,
            "observable": False,
            "stable_observable": False,
            "selected_main": False,
        }
        if dbms != "SQLite" or not has_test:
            candidate_rows.append(base_row)
            continue

        assert isinstance(test, list)
        sql = normalize_test_sql(test)
        results = [run_sqlite(sql, args.timeout_sec) for _ in range(args.repetitions)]
        is_observable = observable(results[0])
        is_stable = is_observable and stable(results)
        case_id = f"sqlancer_sqlite_{index}_{slugify(bug.get('title', 'case'))}"
        base_row.update(
            {
                "case_id": case_id,
                "normalized_bytes": len(sql.encode("utf-8")),
                "normalized_lines": len(sql.splitlines()),
                "normalized_statements": sql.count(";"),
                "observable": is_observable,
                "stable_observable": is_stable,
                "observed_returncode": results[0]["returncode"],
                "observed_stdout_len": len(results[0]["stdout"]),
                "observed_stderr_len": len(results[0]["stderr"]),
                "observed_timeout": results[0]["timeout"],
            }
        )

        if is_stable:
            case_dir = cases_dir / case_id
            case_dir.mkdir(parents=True, exist_ok=True)
            input_path = case_dir / "original.sql"
            metadata_path = case_dir / "metadata.json"
            input_path.write_text(sql, encoding="utf-8")
            metadata = {
                "source": BUGS_JSON_URL,
                "source_sha256": source_sha256,
                "source_index": index,
                "title": bug.get("title"),
                "date": bug.get("date"),
                "status": bug.get("status"),
                "sqlancer_oracle": bug.get("oracle"),
                "links": bug.get("links", {}),
                "original_test": test,
                "normalized_sql_sha256": hashlib.sha256(sql.encode("utf-8")).hexdigest(),
                "sqlite_version": sqlite_version,
                "replay_repetitions": args.repetitions,
                "observed_runs": results,
                "note": "This case is from SQLancer bugs.json. The executable SQL strips report comments; the oracle is the stable signature observed on the current sqlite3 binary.",
            }
            metadata_path.write_text(json.dumps(metadata, ensure_ascii=False, indent=2, sort_keys=True), encoding="utf-8")
            manifest_row = {
                "case_id": case_id,
                "dbms": "sqlite",
                "input_sql": str(input_path),
                "bug_type": bug.get("oracle", "unknown"),
                "source": BUGS_JSON_URL,
                "source_index": index,
                "title": bug.get("title"),
                "status": bug.get("status"),
                "normalized_bytes": len(sql.encode("utf-8")),
                "normalized_statements": sql.count(";"),
                "oracle": build_oracle(results[0]),
            }
            if bug.get("status") == "fixed":
                manifest_rows_all.append(manifest_row)

            selected = (
                bug.get("status") == "fixed"
                and len(sql.encode("utf-8")) >= args.min_bytes
                and sql.count(";") >= args.min_statements
            )
            base_row["selected_main"] = selected
            if selected:
                manifest_rows_main.append(manifest_row)

        candidate_rows.append(base_row)

    write_jsonl(Path(args.candidate_index), candidate_rows)
    write_jsonl(Path(args.all_observable_manifest), manifest_rows_all)
    write_jsonl(Path(args.main_manifest), manifest_rows_main)
    summary = summarize(candidate_rows, candidate_rows and [row for row in candidate_rows if row.get("selected_main")], source_sha256, sqlite_version)
    Path(args.summary).parent.mkdir(parents=True, exist_ok=True)
    Path(args.summary).write_text(json.dumps(summary, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    print(f"Wrote candidate index: {args.candidate_index}")
    print(f"Wrote all fixed observable manifest: {args.all_observable_manifest} ({len(manifest_rows_all)} cases)")
    print(f"Wrote main manifest: {args.main_manifest} ({len(manifest_rows_main)} cases)")
    print(f"Wrote summary: {args.summary}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
