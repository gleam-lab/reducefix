#!/usr/bin/env python3
"""Import selected SQLancer failure-report snippets into the DBMS reduction format."""

from __future__ import annotations

import argparse
import json
import shutil
import subprocess
import urllib.request
from pathlib import Path


BUGS_JSON_URL = "https://raw.githubusercontent.com/sqlancer/bugs/master/bugs.json"
DEFAULT_INDICES = [25, 103, 104, 145, 248]
DEFAULT_FORBID_PATTERNS = ["no such table", "no such column", "syntax error", "parse error"]
DEPENDENCY_ERROR_PATTERNS = ["no such table", "no such column"]


def slugify(text: str, max_len: int = 48) -> str:
    chars = []
    for ch in text.lower():
        if ch.isalnum():
            chars.append(ch)
        elif chars and chars[-1] != "_":
            chars.append("_")
    slug = "".join(chars).strip("_")
    return slug[:max_len].strip("_") or "case"


def load_bugs(path: str | None) -> list[dict]:
    if path:
        return json.loads(Path(path).read_text(encoding="utf-8"))
    with urllib.request.urlopen(BUGS_JSON_URL, timeout=60) as response:
        return json.loads(response.read().decode("utf-8"))


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


def run_sqlite(sql: str, timeout_sec: float) -> tuple[int, str, str]:
    sqlite = shutil.which("sqlite3")
    if not sqlite:
        raise RuntimeError("sqlite3 binary not found on PATH")
    proc = subprocess.run(
        [sqlite, "-batch", "-noheader"],
        input=sql.encode("utf-8"),
        capture_output=True,
        timeout=timeout_sec,
        check=False,
    )
    return (
        proc.returncode,
        proc.stdout.decode("utf-8", errors="replace"),
        proc.stderr.decode("utf-8", errors="replace"),
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
    ]
    for candidate in candidates:
        if candidate.lower() in stderr.lower():
            return candidate
    first_line = next((line.strip() for line in stderr.splitlines() if line.strip()), "")
    return first_line[:120]


def build_oracle(returncode: int, stdout: str, stderr: str) -> dict:
    oracle: dict = {"exit_code": returncode}
    if returncode == 124:
        oracle["timeout"] = True
    if stdout:
        oracle["stdout_equals"] = stdout
    if stderr:
        signature = choose_stderr_signature(stderr)
        if signature:
            oracle["stderr_contains"] = signature
        forbidden = []
        lowered_stderr = stderr.lower()
        for pattern in DEPENDENCY_ERROR_PATTERNS:
            if pattern not in lowered_stderr:
                forbidden.append(pattern)
        if forbidden:
            oracle["forbid_stderr_contains"] = forbidden
    else:
        oracle["forbid_stderr_contains"] = DEFAULT_FORBID_PATTERNS
    return oracle


def main() -> int:
    parser = argparse.ArgumentParser(description="Import selected SQLancer failure-report snippets.")
    parser.add_argument("--bugs-json", default=None, help="Optional local SQLancer bugs.json path.")
    parser.add_argument("--indices", nargs="+", type=int, default=DEFAULT_INDICES)
    parser.add_argument("--out-dir", default="dbms_results/cases")
    parser.add_argument("--manifest", default="dbms_results/manifests/sqlancer_sqlite_real_smoke.jsonl")
    parser.add_argument("--timeout-sec", type=float, default=5.0)
    args = parser.parse_args()

    bugs = load_bugs(args.bugs_json)
    out_dir = Path(args.out_dir)
    manifest_path = Path(args.manifest)
    manifest_path.parent.mkdir(parents=True, exist_ok=True)

    rows = []
    for index in args.indices:
        bug = bugs[index]
        if bug.get("dbms") != "SQLite":
            raise ValueError(f"Index {index} is not a SQLite record: {bug.get('dbms')}")
        test = bug.get("test")
        if not isinstance(test, list) or not test:
            raise ValueError(f"Index {index} has no test list")
        sql = normalize_test_sql(test)
        returncode, stdout, stderr = run_sqlite(sql, args.timeout_sec)
        if returncode == 0 and not stdout and not stderr:
            raise RuntimeError(f"Index {index} produced no observable signature on this SQLite version")

        case_id = f"sqlancer_sqlite_{index}_{slugify(bug.get('title', 'case'))}"
        case_dir = out_dir / case_id
        case_dir.mkdir(parents=True, exist_ok=True)
        input_path = case_dir / "original.sql"
        metadata_path = case_dir / "metadata.json"
        input_path.write_text(sql, encoding="utf-8")
        metadata = {
            "source": BUGS_JSON_URL,
            "source_index": index,
            "title": bug.get("title"),
            "date": bug.get("date"),
            "status": bug.get("status"),
            "sqlancer_oracle": bug.get("oracle"),
            "links": bug.get("links", {}),
            "original_test": test,
            "observed_sqlite_returncode": returncode,
            "observed_sqlite_stdout": stdout,
            "observed_sqlite_stderr": stderr,
            "note": "Oracle below is the signature observed on the current sqlite3 binary, not necessarily the historical SQLite version in which the failure was reported.",
        }
        metadata_path.write_text(json.dumps(metadata, ensure_ascii=False, indent=2, sort_keys=True), encoding="utf-8")
        rows.append(
            {
                "case_id": case_id,
                "dbms": "sqlite",
                "input_sql": str(input_path),
                "bug_type": bug.get("oracle", "unknown"),
                "source": BUGS_JSON_URL,
                "source_index": index,
                "title": bug.get("title"),
                "oracle": build_oracle(returncode, stdout, stderr),
            }
        )

    with manifest_path.open("w", encoding="utf-8") as handle:
        for row in rows:
            handle.write(json.dumps(row, ensure_ascii=False, sort_keys=True) + "\n")

    print(f"Wrote {len(rows)} cases to {manifest_path}")
    for row in rows:
        print(f"- {row['case_id']}: {row['input_sql']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
