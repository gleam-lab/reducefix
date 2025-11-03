#!/bin/bash
# Test RQ2 setup without running full evaluation

echo "=== RQ2 Setup Verification ==="
echo ""

echo "1. Checking required files..."
if [ -f "temp/result_reducer_reducefix_full.json" ]; then
    size=$(du -h temp/result_reducer_reducefix_full.json | cut -f1)
    echo "  ✓ temp/result_reducer_reducefix_full.json ($size)"
else
    echo "  ✗ temp/result_reducer_reducefix_full.json NOT FOUND"
fi

if [ -f "result_python_repairs.json" ]; then
    size=$(du -h result_python_repairs.json | cut -f1)
    echo "  ✓ result_python_repairs.json ($size)"
else
    echo "  ✗ result_python_repairs.json NOT FOUND"
fi

echo ""
echo "2. Checking/Creating reducer_results.json link..."
if [ -L "reducer_results.json" ]; then
    target=$(readlink -f reducer_results.json)
    echo "  ✓ reducer_results.json -> $target"
elif [ -f "reducer_results.json" ]; then
    echo "  ⚠ reducer_results.json exists but is not a symlink"
else
    echo "  Creating link..."
    ln -sf temp/result_reducer_reducefix_full.json reducer_results.json
    echo "  ✓ Created: reducer_results.json -> temp/result_reducer_reducefix_full.json"
fi

echo ""
echo "3. Checking scripts..."
for script in rq2.sh rq2_batch.sh analyze_rq2_table.py analyze_rq2_combined.py; do
    if [ -x "$script" ]; then
        echo "  ✓ $script (executable)"
    elif [ -f "$script" ]; then
        echo "  ⚠ $script (exists but not executable)"
        chmod +x "$script"
        echo "    → Made executable"
    else
        echo "  ✗ $script NOT FOUND"
    fi
done

echo ""
echo "4. Model configurations:"
echo "  - qwen25-coder7b: qwen2.5-coder-7b-instruct"
echo "  - glm4-9b: glm4-9b-chat"
echo "  - qwenplus: qwen-plus"
echo "  - deepseekv3: deepseek-v3"

echo ""
echo "5. Ready to run:"
echo "  ./rq2_batch.sh              # All 4 models"
echo "  ./rq2.sh qwenplus qwen-plus # Single model"
echo ""
echo "=== Setup Complete ==="
