#!/usr/bin/env python3
"""Run SQL-sequence reduction experiments for DBMS reproducers."""

from __future__ import annotations

import argparse
import importlib.util
import json
import re
import shlex
import shutil
import subprocess
import sys
import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable, Iterable, Sequence


INVALID_STDERR_PATTERNS = (
    "no such table",
    "no such column",
    "syntax error",
    "parse error",
    "constraint failed",
    "foreign key constraint failed",
)


class UnsupportedReducer(RuntimeError):
    """Raised when an optional external reducer is not configured."""


@dataclass
class RunResult:
    returncode: int
    stdout: str
    stderr: str
    elapsed_sec: float
    timed_out: bool = False


@dataclass
class TestStats:
    total: int = 0
    interesting: int = 0
    invalid: int = 0
    not_interesting: int = 0
    timeout: int = 0
    last_status: str = "not-run"
    last_reason: str = ""


@dataclass
class SQLStatement:
    text: str
    index: int
    kind: str = "other"
    defines: set[str] = field(default_factory=set)
    refs: set[str] = field(default_factory=set)
    is_oracle: bool = False


def read_jsonl(path: Path) -> Iterable[dict]:
    with path.open("r", encoding="utf-8") as handle:
        for line_no, line in enumerate(handle, start=1):
            line = line.strip()
            if not line:
                continue
            try:
                yield json.loads(line)
            except json.JSONDecodeError as exc:
                raise ValueError(f"{path}:{line_no}: invalid JSONL row: {exc}") from exc


def split_sql_statements(sql: str) -> list[str]:
    """Split SQL into semicolon-terminated statements while preserving text."""
    statements: list[str] = []
    start = 0
    i = 0
    quote: str | None = None
    line_comment = False
    block_comment = False
    while i < len(sql):
        ch = sql[i]
        nxt = sql[i + 1] if i + 1 < len(sql) else ""

        if line_comment:
            if ch == "\n":
                line_comment = False
            i += 1
            continue

        if block_comment:
            if ch == "*" and nxt == "/":
                block_comment = False
                i += 2
                continue
            i += 1
            continue

        if quote:
            if ch == quote:
                if i + 1 < len(sql) and sql[i + 1] == quote:
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
            line_comment = True
            i += 2
            continue
        if ch == "/" and nxt == "*":
            block_comment = True
            i += 2
            continue
        if ch == ";":
            statement = sql[start : i + 1].strip()
            if statement:
                statements.append(statement)
            start = i + 1
        i += 1

    tail = sql[start:].strip()
    if tail:
        statements.append(tail)
    return statements


def strip_sql_comments(statement: str) -> str:
    statement = re.sub(r"/\*.*?\*/", " ", statement, flags=re.DOTALL)
    statement = re.sub(r"--[^\n]*", " ", statement)
    return statement.strip()


def normalize_ident(name: str) -> str:
    return name.strip().strip("`\"[]").lower()


def collect_table_refs(clean: str) -> set[str]:
    refs: set[str] = set()
    patterns = (
        r"\bFROM\s+([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)",
        r"\bJOIN\s+([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)",
        r"\bINTO\s+([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)",
        r"\bUPDATE\s+([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)",
        r"\bDELETE\s+FROM\s+([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)",
        r"\bON\s+([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)\s*\(",
    )
    for pattern in patterns:
        for match in re.finditer(pattern, clean, flags=re.IGNORECASE):
            refs.add(normalize_ident(match.group(1)))
    return refs


def classify_statement(text: str, index: int) -> SQLStatement:
    clean = strip_sql_comments(text)
    upper = clean.upper()
    stmt = SQLStatement(text=text.strip(), index=index)

    match = re.match(r"CREATE\s+TABLE\s+(?:IF\s+NOT\s+EXISTS\s+)?([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)", clean, flags=re.IGNORECASE)
    if match:
        stmt.kind = "create-table"
        stmt.defines.add(normalize_ident(match.group(1)))
        return stmt

    match = re.match(r"CREATE\s+VIEW\s+(?:IF\s+NOT\s+EXISTS\s+)?([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)", clean, flags=re.IGNORECASE)
    if match:
        stmt.kind = "create-view"
        stmt.defines.add(normalize_ident(match.group(1)))
        stmt.refs |= collect_table_refs(clean)
        return stmt

    match = re.match(r"CREATE\s+(?:UNIQUE\s+)?INDEX\s+(?:IF\s+NOT\s+EXISTS\s+)?([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)\s+ON\s+([`\"\[]?[A-Za-z_][\w$]*[`\"\]]?)", clean, flags=re.IGNORECASE)
    if match:
        stmt.kind = "create-index"
        stmt.defines.add(normalize_ident(match.group(1)))
        stmt.refs.add(normalize_ident(match.group(2)))
        return stmt

    if upper.startswith("INSERT"):
        stmt.kind = "insert"
        stmt.refs |= collect_table_refs(clean)
        return stmt
    if upper.startswith("UPDATE"):
        stmt.kind = "update"
        stmt.refs |= collect_table_refs(clean)
        return stmt
    if upper.startswith("DELETE"):
        stmt.kind = "delete"
        stmt.refs |= collect_table_refs(clean)
        return stmt
    if upper.startswith(("SELECT", "WITH", "VALUES")):
        stmt.kind = "query"
        stmt.refs |= collect_table_refs(clean)
        stmt.is_oracle = True
        return stmt
    if upper.startswith(("PRAGMA", "SET", "ANALYZE")):
        stmt.kind = "config"
        stmt.refs |= collect_table_refs(clean)
        return stmt

    stmt.refs |= collect_table_refs(clean)
    return stmt


def join_statements(statements: Sequence[str]) -> str:
    return "\n".join(stmt.strip() for stmt in statements if stmt.strip()) + "\n"


def partition_ranges(n: int, granularity: int) -> list[range]:
    if n <= 0:
        return []
    chunk = max(1, n // max(1, granularity))
    ranges: list[range] = []
    start = 0
    while start < n:
        end = min(n, start + chunk)
        ranges.append(range(start, end))
        start = end
    return ranges


def ddmin_units(
    units: list[str],
    test_fn: Callable[[str], bool],
    *,
    compose: Callable[[list[str]], str] | None = None,
    max_time_sec: float | None = None,
    verbose: bool = False,
    label: str = "ddmin",
) -> list[str]:
    if not units:
        return units
    compose = compose or (lambda xs: "".join(xs))
    start_time = time.time()
    granularity = 2
    current = list(units)
    while len(current) > 1:
        if max_time_sec and time.time() - start_time >= max_time_sec:
            if verbose:
                print(f"[{label}] Time budget reached; returning current candidate")
            break
        made_progress = False
        n = len(current)

        for part in partition_ranges(n, granularity):
            candidate = current[: part.start] + current[part.stop :]
            if not candidate:
                continue
            if test_fn(compose(candidate)):
                if verbose:
                    print(f"[{label}] Removed {part.stop - part.start} units ({n}->{len(candidate)})")
                current = candidate
                granularity = 2
                made_progress = True
                break
        if made_progress:
            continue

        for part in partition_ranges(n, granularity):
            if part.start == 0 and part.stop == n:
                continue
            candidate = current[part.start : part.stop]
            if not candidate:
                continue
            if test_fn(compose(candidate)):
                if verbose:
                    print(f"[{label}] Kept {len(candidate)} of {n} units")
                current = candidate
                granularity = 2
                made_progress = True
                break
        if made_progress:
            continue

        if granularity >= n:
            break
        granularity = min(n, granularity * 2)
    return current


def ddmin_index_subset(
    statements: list[SQLStatement],
    variable_indices: list[int],
    locked_indices: set[int],
    test_fn: Callable[[str], bool],
    *,
    max_time_sec: float | None = None,
    verbose: bool = False,
) -> set[int]:
    start_time = time.time()
    current = list(variable_indices)
    granularity = 2

    def compose_indices(indices: Sequence[int]) -> str:
        keep = set(indices) | locked_indices
        return join_statements([stmt.text for stmt in statements if stmt.index in keep])

    while len(current) > 1:
        if max_time_sec and time.time() - start_time >= max_time_sec:
            if verbose:
                print("[reducefix-sql] Time budget reached during dependency-aware ddmin")
            break
        made_progress = False
        n = len(current)
        for part in partition_ranges(n, granularity):
            candidate = current[: part.start] + current[part.stop :]
            if test_fn(compose_indices(candidate)):
                if verbose:
                    print(f"[reducefix-sql] Removed {part.stop - part.start} variable statements ({n}->{len(candidate)})")
                current = candidate
                granularity = 2
                made_progress = True
                break
        if made_progress:
            continue
        for part in partition_ranges(n, granularity):
            if part.start == 0 and part.stop == n:
                continue
            candidate = current[part.start : part.stop]
            if test_fn(compose_indices(candidate)):
                if verbose:
                    print(f"[reducefix-sql] Retained {len(candidate)} variable statements")
                current = candidate
                granularity = 2
                made_progress = True
                break
        if made_progress:
            continue
        if granularity >= n:
            break
        granularity = min(n, granularity * 2)
    return set(current) | locked_indices


def split_insert_values_groups(statement: str) -> tuple[str, list[str], str] | None:
    match = re.search(r"\bVALUES\b", statement, flags=re.IGNORECASE)
    if not match:
        return None

    prefix = statement[: match.end()]
    rest = statement[match.end() :]
    groups: list[str] = []
    i = 0
    quote: str | None = None
    while i < len(rest):
        while i < len(rest) and rest[i] in " \t\r\n,":
            i += 1
        if i >= len(rest) or rest[i] != "(":
            break

        start = i
        depth = 0
        while i < len(rest):
            ch = rest[i]
            if quote:
                if ch == quote:
                    if i + 1 < len(rest) and rest[i + 1] == quote:
                        i += 2
                        continue
                    quote = None
                i += 1
                continue
            if ch in ("'", '"', "`"):
                quote = ch
                i += 1
                continue
            if ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0:
                    i += 1
                    groups.append(rest[start:i].strip())
                    break
            i += 1
        if depth != 0:
            return None

    suffix = rest[i:].strip()
    if len(groups) <= 1:
        return None
    return prefix.rstrip() + " ", groups, suffix


def compose_insert_values(prefix: str, groups: Sequence[str], suffix: str) -> str:
    body = ", ".join(group.strip() for group in groups)
    suffix = suffix.strip()
    if suffix:
        if suffix.startswith(";"):
            return prefix + body + suffix
        return prefix + body + " " + suffix
    return prefix + body + ";"


def shrink_insert_values_in_kept_statements(
    statements: list[SQLStatement],
    kept: set[int],
    test_fn: Callable[[str], bool],
    *,
    max_time_sec: float | None,
    verbose: bool,
) -> None:
    start_time = time.time()
    for stmt in statements:
        if stmt.index not in kept or stmt.kind != "insert":
            continue
        parsed = split_insert_values_groups(stmt.text)
        if not parsed:
            continue
        prefix, groups, suffix = parsed
        if verbose:
            print(f"[reducefix-sql] Trying tuple-level reduction in INSERT #{stmt.index}: {len(groups)} tuples")

        def compose_with_groups(candidate_groups: list[str]) -> str:
            old_text = stmt.text
            stmt.text = compose_insert_values(prefix, candidate_groups, suffix)
            try:
                return join_statements([s.text for s in statements if s.index in kept])
            finally:
                stmt.text = old_text

        remaining_budget = None
        if max_time_sec is not None:
            elapsed = time.time() - start_time
            remaining_budget = max(0.1, max_time_sec - elapsed)

        reduced_groups = ddmin_units(
            groups,
            test_fn,
            compose=compose_with_groups,
            max_time_sec=remaining_budget,
            verbose=verbose,
            label="reducefix-sql-values",
        )
        if len(reduced_groups) < len(groups):
            stmt.text = compose_insert_values(prefix, reduced_groups, suffix)
            if verbose:
                print(f"[reducefix-sql] Reduced INSERT #{stmt.index}: {len(groups)}->{len(reduced_groups)} tuples")


def run_sqlite(sql: str, timeout_sec: float) -> RunResult:
    binary = shutil.which("sqlite3")
    if not binary:
        raise RuntimeError("sqlite3 binary not found on PATH")
    start = time.time()
    try:
        proc = subprocess.run(
            [binary, "-batch", "-noheader"],
            input=sql.encode("utf-8"),
            capture_output=True,
            timeout=timeout_sec,
            check=False,
        )
        stdout = proc.stdout.decode("utf-8", errors="replace")
        stderr = proc.stderr.decode("utf-8", errors="replace")
        return RunResult(proc.returncode, stdout, stderr, time.time() - start)
    except subprocess.TimeoutExpired as exc:
        stdout = exc.stdout.decode("utf-8", errors="replace") if isinstance(exc.stdout, bytes) else (exc.stdout or "")
        stderr = exc.stderr.decode("utf-8", errors="replace") if isinstance(exc.stderr, bytes) else (exc.stderr or "")
        return RunResult(124, stdout, stderr, time.time() - start, timed_out=True)


def run_dbms(dbms: str, sql: str, timeout_sec: float) -> RunResult:
    if dbms == "sqlite":
        return run_sqlite(sql, timeout_sec)
    raise ValueError(f"Unsupported dbms '{dbms}'. Currently supported: sqlite")


def oracle_matches(result: RunResult, oracle: dict) -> tuple[str, str]:
    if result.timed_out:
        if oracle.get("timeout"):
            return "interesting", "expected timeout"
        return "timeout", "runner timed out"

    expected_exit = oracle.get("exit_code")
    if expected_exit is not None and result.returncode != int(expected_exit):
        if any(pattern in result.stderr.lower() for pattern in INVALID_STDERR_PATTERNS):
            return "invalid", f"exit={result.returncode}, invalid stderr"
        return "not_interesting", f"exit={result.returncode}, expected={expected_exit}"

    for pattern in oracle.get("forbid_stderr_contains", []):
        if pattern.lower() in result.stderr.lower():
            return "invalid", f"forbidden stderr pattern: {pattern}"

    stdout = result.stdout
    stderr = result.stderr
    if "stdout_equals" in oracle and stdout != oracle["stdout_equals"]:
        return "not_interesting", "stdout_equals mismatch"
    if "stdout_contains" in oracle and oracle["stdout_contains"] not in stdout:
        return "not_interesting", "stdout_contains mismatch"
    if "stderr_contains" in oracle and oracle["stderr_contains"] not in stderr:
        return "not_interesting", "stderr_contains mismatch"
    if oracle.get("exit_nonzero") and result.returncode == 0:
        return "not_interesting", "expected non-zero exit"
    return "interesting", "oracle matched"


def make_test_fn(case: dict, timeout_sec: float, stats: TestStats) -> Callable[[str], bool]:
    dbms = case["dbms"]
    oracle = case.get("oracle", {})

    def test_fn(candidate_sql: str) -> bool:
        stats.total += 1
        result = run_dbms(dbms, candidate_sql, timeout_sec)
        status, reason = oracle_matches(result, oracle)
        stats.last_status = status
        stats.last_reason = reason
        if status == "interesting":
            stats.interesting += 1
            return True
        if status == "invalid":
            stats.invalid += 1
        elif status == "timeout":
            stats.timeout += 1
        else:
            stats.not_interesting += 1
        return False

    return test_fn


def reduce_line_ddmin(sql: str, test_fn: Callable[[str], bool], max_time_sec: float | None, verbose: bool) -> str:
    lines = sql.splitlines(keepends=True)
    reduced = ddmin_units(
        lines,
        test_fn,
        compose=lambda xs: "".join(xs),
        max_time_sec=max_time_sec,
        verbose=verbose,
        label="line-ddmin",
    )
    return "".join(reduced)


def reduce_statement_ddmin(sql: str, test_fn: Callable[[str], bool], max_time_sec: float | None, verbose: bool) -> str:
    statements = split_sql_statements(sql)
    reduced = ddmin_units(
        statements,
        test_fn,
        compose=join_statements,
        max_time_sec=max_time_sec,
        verbose=verbose,
        label="statement-ddmin",
    )
    return join_statements(reduced)


def reduce_reducefix_sql(sql: str, test_fn: Callable[[str], bool], max_time_sec: float | None, verbose: bool) -> str:
    raw_statements = split_sql_statements(sql)
    statements = [classify_statement(text, idx) for idx, text in enumerate(raw_statements)]
    if not statements:
        return sql

    oracle_indices = {stmt.index for stmt in statements if stmt.is_oracle}
    if not oracle_indices:
        oracle_indices = {statements[-1].index}

    oracle_refs: set[str] = set()
    for stmt in statements:
        if stmt.index in oracle_indices:
            oracle_refs |= stmt.refs

    locked: set[int] = set(oracle_indices)
    if oracle_refs:
        for stmt in statements:
            if stmt.kind in {"create-table", "create-view"} and stmt.defines & oracle_refs:
                locked.add(stmt.index)

    current_keep = {stmt.index for stmt in statements}

    # Remove whole unrelated dependency groups first. This is the key SQL-aware step.
    groups: dict[str, set[int]] = {}
    for stmt in statements:
        keys = stmt.defines | stmt.refs
        for key in keys:
            groups.setdefault(key, set()).add(stmt.index)

    for table, indices in sorted(groups.items()):
        if table in oracle_refs:
            continue
        candidate_keep = current_keep - indices
        if not candidate_keep or not locked.issubset(candidate_keep):
            continue
        candidate_sql = join_statements([stmt.text for stmt in statements if stmt.index in candidate_keep])
        if test_fn(candidate_sql):
            if verbose:
                print(f"[reducefix-sql] Removed dependency group '{table}' ({len(indices)} statements)")
            current_keep = candidate_keep

    variable = sorted(idx for idx in current_keep if idx not in locked)
    kept = ddmin_index_subset(
        statements,
        variable,
        locked,
        test_fn,
        max_time_sec=max_time_sec,
        verbose=verbose,
    )
    kept &= current_keep
    if not locked.issubset(kept):
        kept |= locked
    shrink_insert_values_in_kept_statements(
        statements,
        kept,
        test_fn,
        max_time_sec=max_time_sec,
        verbose=verbose,
    )
    return join_statements([stmt.text for stmt in statements if stmt.index in kept])


def reduce_reducefix_sql_cleanup(sql: str, test_fn: Callable[[str], bool], max_time_sec: float | None, verbose: bool) -> str:
    """Run the SQL-aware reducer, then apply generic statement cleanup.

    The first phase crosses SQL validity barriers by preserving schema and
    dependency structure. The second phase removes any statements that became
    redundant after those format-aware rewrites, using the same oracle.
    """
    reduced = reduce_reducefix_sql(sql, test_fn, max_time_sec, verbose)
    statements = split_sql_statements(reduced)
    cleaned = ddmin_units(
        statements,
        test_fn,
        compose=join_statements,
        max_time_sec=max_time_sec,
        verbose=verbose,
        label="reducefix-sql-cleanup",
    )
    return join_statements(cleaned)


def load_generated_reducer(path: Path) -> Callable[[str, Callable[[str], bool], bool], str]:
    spec = importlib.util.spec_from_file_location("generated_sql_reducer", path)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"Cannot import generated reducer from {path}")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    reducer = getattr(module, "generated_reduce_sql", None)
    if reducer is None:
        raise RuntimeError(f"{path} does not define generated_reduce_sql")
    return reducer


def analyze_sql_shape(sql: str) -> str:
    statements = [classify_statement(text, idx) for idx, text in enumerate(split_sql_statements(sql))]
    counts: dict[str, int] = {}
    refs: set[str] = set()
    defines: set[str] = set()
    for stmt in statements:
        counts[stmt.kind] = counts.get(stmt.kind, 0) + 1
        refs |= stmt.refs
        defines |= stmt.defines
    parts = [
        f"bytes={len(sql.encode('utf-8'))}",
        f"statements={len(statements)}",
        "statement_kinds=" + json.dumps(counts, sort_keys=True),
        "defined_objects=" + ", ".join(sorted(defines)) if defines else "defined_objects=<none>",
        "referenced_objects=" + ", ".join(sorted(refs)) if refs else "referenced_objects=<none>",
    ]
    return "\n".join(parts)


def emit_reducer_prompt(case: dict, sql: str, template_path: Path, output_dir: Path) -> Path:
    template = template_path.read_text(encoding="utf-8")
    prompt = template.format(
        dbms=case["dbms"],
        oracle_description=json.dumps(case.get("oracle", {}), ensure_ascii=False, sort_keys=True),
        format_analysis=analyze_sql_shape(sql),
        original_sql=sql,
    )
    output_dir.mkdir(parents=True, exist_ok=True)
    out_path = output_dir / f"{case['case_id']}.reducer-sql.prompt"
    out_path.write_text(prompt, encoding="utf-8")
    return out_path


def reduce_external_command(
    sql: str,
    case: dict,
    command_template: str | None,
    *,
    output_dir: Path | None,
    method: str,
    timeout_sec: float,
) -> str:
    if not command_template:
        raise UnsupportedReducer(f"{method} requires a command template")
    work_dir = output_dir or Path("/tmp/reducefix_dbms_external")
    work_dir.mkdir(parents=True, exist_ok=True)
    input_path = work_dir / f"{case['case_id']}.{method}.input.sql"
    output_path = work_dir / f"{case['case_id']}.{method}.output.sql"
    input_path.write_text(sql, encoding="utf-8")
    if output_path.exists():
        output_path.unlink()
    command = command_template.format(
        input=shlex.quote(str(input_path)),
        output=shlex.quote(str(output_path)),
        dbms=shlex.quote(case["dbms"]),
        case_id=shlex.quote(case["case_id"]),
    )
    proc = subprocess.run(
        command,
        shell=True,
        text=True,
        capture_output=True,
        timeout=timeout_sec,
        check=False,
    )
    if proc.returncode != 0:
        stderr_tail = proc.stderr[-500:].replace("\n", " ")
        raise RuntimeError(f"{method} command failed with exit {proc.returncode}: {stderr_tail}")
    if not output_path.exists():
        raise RuntimeError(f"{method} did not create expected output file: {output_path}")
    return output_path.read_text(encoding="utf-8")


def run_method(case: dict, method: str, args: argparse.Namespace) -> dict:
    input_path = Path(case["input_sql"])
    original_sql = input_path.read_text(encoding="utf-8")
    original_statements = split_sql_statements(original_sql)

    pre_stats = TestStats()
    pre_test = make_test_fn(case, args.timeout_sec, pre_stats)
    original_interesting = pre_test(original_sql)
    if not original_interesting:
        return {
            "case_id": case["case_id"],
            "method": method,
            "status": "original-not-interesting",
            "original_bytes": len(original_sql.encode("utf-8")),
            "original_statements": len(original_statements),
            "oracle_status": pre_stats.last_status,
            "oracle_reason": pre_stats.last_reason,
        }

    stats = TestStats()
    test_fn = make_test_fn(case, args.timeout_sec, stats)
    start = time.time()

    if method == "line-ddmin":
        reduced_sql = reduce_line_ddmin(original_sql, test_fn, args.max_time_sec, args.verbose)
    elif method == "statement-ddmin":
        reduced_sql = reduce_statement_ddmin(original_sql, test_fn, args.max_time_sec, args.verbose)
    elif method == "reducefix-sql":
        reduced_sql = reduce_reducefix_sql(original_sql, test_fn, args.max_time_sec, args.verbose)
    elif method == "reducefix-sql-cleanup":
        reduced_sql = reduce_reducefix_sql_cleanup(original_sql, test_fn, args.max_time_sec, args.verbose)
    elif method == "generated-reducer":
        reducer_path_value = case.get("generated_reducer") or args.generated_reducer
        if not reducer_path_value:
            raise UnsupportedReducer("generated-reducer requires --generated-reducer or manifest generated_reducer")
        reducer_path = Path(reducer_path_value)
        reducer = load_generated_reducer(reducer_path)
        reduced_sql = reducer(original_sql, test_fn, args.verbose)
    elif method == "sqlancer-reducer":
        reduced_sql = reduce_external_command(
            original_sql,
            case,
            case.get("sqlancer_reducer_command") or args.sqlancer_reducer_command,
            output_dir=Path(args.output_sql_dir) if args.output_sql_dir else None,
            method=method,
            timeout_sec=args.external_timeout_sec,
        )
    elif method == "pure-llm":
        reduced_sql = reduce_external_command(
            original_sql,
            case,
            case.get("pure_llm_command") or args.pure_llm_command,
            output_dir=Path(args.output_sql_dir) if args.output_sql_dir else None,
            method=method,
            timeout_sec=args.external_timeout_sec,
        )
    elif method == "creduce":
        reduced_sql = reduce_external_command(
            original_sql,
            case,
            case.get("creduce_command") or args.creduce_command,
            output_dir=Path(args.output_sql_dir) if args.output_sql_dir else None,
            method=method,
            timeout_sec=args.external_timeout_sec,
        )
    else:
        raise ValueError(f"Unknown method: {method}")

    elapsed = time.time() - start
    final_stats = TestStats()
    final_interesting = make_test_fn(case, args.timeout_sec, final_stats)(reduced_sql)
    status = "success" if final_interesting else "failed-final-check"

    original_bytes = len(original_sql.encode("utf-8"))
    reduced_bytes = len(reduced_sql.encode("utf-8"))
    reduced_statements = split_sql_statements(reduced_sql)

    output_dir = Path(args.output_sql_dir) if args.output_sql_dir else None
    output_sql_path = None
    if output_dir:
        output_dir.mkdir(parents=True, exist_ok=True)
        output_sql_path = output_dir / f"{case['case_id']}.{method}.sql"
        output_sql_path.write_text(reduced_sql, encoding="utf-8")

    return {
        "case_id": case["case_id"],
        "dbms": case["dbms"],
        "bug_type": case.get("bug_type", "unknown"),
        "method": method,
        "status": status,
        "original_bytes": original_bytes,
        "reduced_bytes": reduced_bytes,
        "compression_rate": 100.0 * (1.0 - reduced_bytes / original_bytes) if original_bytes else 0.0,
        "original_statements": len(original_statements),
        "reduced_statements": len(reduced_statements),
        "statement_compression_rate": 100.0 * (1.0 - len(reduced_statements) / len(original_statements)) if original_statements else 0.0,
        "tests": stats.total,
        "interesting_tests": stats.interesting,
        "invalid_tests": stats.invalid,
        "not_interesting_tests": stats.not_interesting,
        "timeout_tests": stats.timeout,
        "invalid_rate": stats.invalid / stats.total if stats.total else 0.0,
        "elapsed_sec": elapsed,
        "output_sql": str(output_sql_path) if output_sql_path else None,
        "final_oracle_status": final_stats.last_status,
        "final_oracle_reason": final_stats.last_reason,
    }


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run DBMS SQL-sequence reduction experiments.")
    parser.add_argument("--manifest", required=True, help="JSONL manifest path.")
    parser.add_argument("--methods", nargs="+", default=["line-ddmin", "statement-ddmin", "reducefix-sql"])
    parser.add_argument("--out", required=True, help="Output JSONL results path.")
    parser.add_argument("--output-sql-dir", default=None, help="Optional directory for reduced SQL files.")
    parser.add_argument("--generated-reducer", default=None, help="Path for method=generated-reducer.")
    parser.add_argument("--pure-llm-command", default=None, help="External command template for method=pure-llm. Use {input} and {output}.")
    parser.add_argument("--sqlancer-reducer-command", default=None, help="External command template for method=sqlancer-reducer. Use {input} and {output}.")
    parser.add_argument("--creduce-command", default=None, help="External command template for method=creduce. Use {input} and {output}.")
    parser.add_argument("--external-timeout-sec", type=float, default=600.0, help="Timeout for external reducer commands.")
    parser.add_argument("--emit-prompts-dir", default=None, help="Optional directory for instantiated SQL reducer prompts.")
    parser.add_argument("--prompt-template", default="prompt_formats/reducer-sql.prompt", help="Prompt template for --emit-prompts-dir.")
    parser.add_argument("--timeout-sec", type=float, default=5.0, help="Per-candidate DBMS execution timeout.")
    parser.add_argument("--max-time-sec", type=float, default=60.0, help="Per-method reduction time budget.")
    parser.add_argument("--verbose", action="store_true")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    out_path = Path(args.out)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    cases = list(read_jsonl(Path(args.manifest)))
    if args.emit_prompts_dir:
        prompt_dir = Path(args.emit_prompts_dir)
        template_path = Path(args.prompt_template)
        for case in cases:
            sql = Path(case["input_sql"]).read_text(encoding="utf-8")
            prompt_path = emit_reducer_prompt(case, sql, template_path, prompt_dir)
            if args.verbose:
                print(f"[dbms] Wrote reducer prompt: {prompt_path}")
    with out_path.open("w", encoding="utf-8") as handle:
        for case in cases:
            for method in args.methods:
                if args.verbose:
                    print(f"[dbms] Running {method} on {case['case_id']}")
                try:
                    result = run_method(case, method, args)
                except UnsupportedReducer as exc:
                    result = {
                        "case_id": case.get("case_id", "<unknown>"),
                        "method": method,
                        "status": "unsupported",
                        "reason": str(exc),
                    }
                except Exception as exc:
                    result = {
                        "case_id": case.get("case_id", "<unknown>"),
                        "method": method,
                        "status": "error",
                        "error": f"{type(exc).__name__}: {exc}",
                    }
                handle.write(json.dumps(result, ensure_ascii=False, sort_keys=True) + "\n")
                handle.flush()
                if args.verbose:
                    status = result.get("status")
                    cr = result.get("compression_rate")
                    cr_text = f", CR={cr:.1f}%" if isinstance(cr, float) else ""
                    print(f"[dbms] {case['case_id']} {method}: {status}{cr_text}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
