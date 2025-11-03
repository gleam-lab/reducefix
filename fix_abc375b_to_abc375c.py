#!/usr/bin/env python3
"""
Fix all references from abc375b to abc375c
- Rename directories
- Update JSON files
- Update any other references
"""

import json
import os
import shutil

def rename_directory(old_path, new_path):
    """Rename directory if it exists"""
    if os.path.exists(old_path):
        if os.path.exists(new_path):
            print(f"⚠️  {new_path} already exists, skipping directory rename")
            return False
        print(f"📁 Renaming directory: {old_path} → {new_path}")
        shutil.move(old_path, new_path)
        return True
    else:
        print(f"✓ Directory {old_path} not found (already renamed or doesn't exist)")
        return False

def update_json_file(filename):
    """Update JSON file to replace abc375b with abc375c"""
    if not os.path.exists(filename):
        print(f"✓ {filename} not found, skipping")
        return 0
    
    print(f"📖 Processing {filename}...")
    
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Count occurrences
        count = content.count('abc375b')
        
        if count == 0:
            print(f"  ✓ No abc375b found in {filename}")
            return 0
        
        # Replace all occurrences
        new_content = content.replace('abc375b', 'abc375c')
        
        # Backup original
        backup_path = f"temp/{filename}.backup"
        os.makedirs('temp', exist_ok=True)
        with open(backup_path, 'w', encoding='utf-8') as f:
            f.write(content)
        
        # Write updated content
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(new_content)
        
        print(f"  ✓ Updated {count} occurrences (backup: {backup_path})")
        return count
    
    except Exception as e:
        print(f"  ✗ Error processing {filename}: {e}")
        return 0

def main():
    print("="*80)
    print("Fixing abc375b → abc375c")
    print("="*80)
    print()
    
    # 1. Rename directory
    print("Step 1: Rename directories")
    print("-"*80)
    rename_directory("results/abc375b", "results/abc375c")
    print()
    
    # 2. Update JSON files
    print("Step 2: Update JSON files")
    print("-"*80)
    
    json_files = [
        'result_chatrepair.json',
        'result_python_qwenplus.json',
        'result_python_repairs.json',
    ]
    
    total_changes = 0
    for filename in json_files:
        changes = update_json_file(filename)
        total_changes += changes
    
    print()
    print("="*80)
    print(f"Summary: {total_changes} total replacements made")
    print("="*80)
    print()
    
    # 3. Check if any references remain
    print("Step 3: Verify no abc375b references remain")
    print("-"*80)
    
    import subprocess
    result = subprocess.run(
        ['grep', '-r', 'abc375b', '.', '--include=*.json', '--exclude-dir=temp'],
        capture_output=True,
        text=True
    )
    
    if result.stdout:
        print("⚠️  Some references still remain:")
        print(result.stdout)
    else:
        print("✓ All abc375b references updated to abc375c!")
    
    print()
    print("="*80)
    print("Done! All abc375b → abc375c conversions complete")
    print("="*80)

if __name__ == "__main__":
    main()

