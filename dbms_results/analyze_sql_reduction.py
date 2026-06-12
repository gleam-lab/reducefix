#!/usr/bin/env python3
"""Summarize DBMS SQL reduction JSONL results."""

from __future__ import annotations

import argparse
import csv
import json
from collections import defaultdict
from math import comb
from pathlib import Path
from statistics import median


def read_jsonl(path: Path) -> list[dict]:
    rows: list[dict] = []
    with path.open("r", encoding="utf-8") as handle:
        for line in handle:
            line = line.strip()
            if line:
                rows.append(json.loads(line))
    return rows


def mean(values: list[float]) -> float:
    return sum(values) / len(values) if values else 0.0


def method_order(rows: list[dict]) -> list[str]:
    order: list[str] = []
    for row in rows:
        method = row.get("method", "<unknown>")
        if method not in order:
            order.append(method)
    return order


def successful(rows: list[dict]) -> list[dict]:
    return [row for row in rows if row.get("status") == "success"]


def metric(row: dict, key: str) -> float:
    return float(row.get(key, 0.0))


def summarize_method(items: list[dict]) -> dict:
    successes = successful(items)
    return {
        "n": len(items),
        "success": len(successes),
        "avg_cr": mean([metric(row, "compression_rate") for row in successes]),
        "median_cr": median([metric(row, "compression_rate") for row in successes]) if successes else 0.0,
        "avg_reduced_bytes": mean([metric(row, "reduced_bytes") for row in successes]),
        "median_reduced_bytes": median([metric(row, "reduced_bytes") for row in successes]) if successes else 0.0,
        "avg_stmt_cr": mean([metric(row, "statement_compression_rate") for row in successes]),
        "median_stmt_cr": median([metric(row, "statement_compression_rate") for row in successes]) if successes else 0.0,
        "avg_reduced_statements": mean([metric(row, "reduced_statements") for row in successes]),
        "median_reduced_statements": median([metric(row, "reduced_statements") for row in successes]) if successes else 0.0,
        "avg_invalid_rate": mean([metric(row, "invalid_rate") for row in successes]),
        "median_invalid_rate": median([metric(row, "invalid_rate") for row in successes]) if successes else 0.0,
        "avg_tests": mean([metric(row, "tests") for row in successes]),
        "median_tests": median([metric(row, "tests") for row in successes]) if successes else 0.0,
        "avg_time_sec": mean([metric(row, "elapsed_sec") for row in successes]),
        "median_time_sec": median([metric(row, "elapsed_sec") for row in successes]) if successes else 0.0,
    }


def one_sided_sign_p(better: int, worse: int) -> float:
    n = better + worse
    if n == 0:
        return 1.0
    return sum(comb(n, k) for k in range(better, n + 1)) / (2**n)


def compare_metric(rows: list[dict], method: str, baseline: str, key: str, direction: str) -> dict:
    by_case_method = {(row.get("case_id"), row.get("method")): row for row in rows if row.get("status") == "success"}
    case_ids = sorted(
        {
            case_id
            for case_id, row_method in by_case_method
            if row_method == method and (case_id, baseline) in by_case_method
        }
    )
    deltas: list[float] = []
    better = 0
    tie = 0
    worse = 0
    examples_better: list[dict] = []
    examples_worse: list[dict] = []
    eps = 1e-9
    for case_id in case_ids:
        delta = metric(by_case_method[(case_id, method)], key) - metric(by_case_method[(case_id, baseline)], key)
        deltas.append(delta)
        is_better = delta > eps if direction == "higher" else delta < -eps
        is_worse = delta < -eps if direction == "higher" else delta > eps
        if is_better:
            better += 1
            if len(examples_better) < 8:
                examples_better.append({"case_id": case_id, "delta": delta})
        elif is_worse:
            worse += 1
            if len(examples_worse) < 8:
                examples_worse.append({"case_id": case_id, "delta": delta})
        else:
            tie += 1
    return {
        "direction": direction,
        "mean_delta": mean(deltas),
        "median_delta": median(deltas) if deltas else 0.0,
        "better": better,
        "tie": tie,
        "worse": worse,
        "one_sided_sign_p": one_sided_sign_p(better, worse),
        "examples_better": examples_better,
        "examples_worse": examples_worse,
    }


def comparison_name(method: str, baseline: str) -> str:
    return f"{method.replace('-', '_')}_vs_{baseline.replace('-', '_')}"


def compare_methods(rows: list[dict], method: str, baseline: str) -> dict:
    metric_specs = {
        "compression_rate": "higher",
        "statement_compression_rate": "higher",
        "invalid_rate": "lower",
        "tests": "lower",
        "elapsed_sec": "lower",
    }
    return {
        key: compare_metric(rows, method, baseline, key, direction)
        for key, direction in metric_specs.items()
    }


def build_summary(rows: list[dict], results_path: Path) -> dict:
    grouped: dict[str, list[dict]] = defaultdict(list)
    for row in rows:
        grouped[row.get("method", "<unknown>")].append(row)

    methods = method_order(rows)
    comparisons: dict[str, dict] = {}
    for baseline in ("statement-ddmin", "line-ddmin"):
        if baseline not in methods:
            continue
        for method in methods:
            if method == baseline:
                continue
            comparisons[comparison_name(method, baseline)] = compare_methods(rows, method, baseline)
    if "reducefix-sql-cleanup" in methods and "reducefix-sql" in methods:
        comparisons[comparison_name("reducefix-sql-cleanup", "reducefix-sql")] = compare_methods(
            rows,
            "reducefix-sql-cleanup",
            "reducefix-sql",
        )

    return {
        "results_file": str(results_path),
        "n_cases": len({row.get("case_id") for row in rows}),
        "methods": {method: summarize_method(grouped[method]) for method in methods},
        "comparisons": comparisons,
    }


def write_case_table(rows: list[dict], path: Path) -> None:
    methods = method_order(rows)
    by_case: dict[str, dict[str, dict]] = defaultdict(dict)
    case_meta: dict[str, dict] = {}
    for row in rows:
        case_id = row.get("case_id", "")
        method = row.get("method", "")
        by_case[case_id][method] = row
        case_meta.setdefault(case_id, row)

    fields = ["case_id", "bug_type", "original_bytes", "original_statements"]
    for method in methods:
        fields.extend(
            [
                f"{method}_status",
                f"{method}_reduced_bytes",
                f"{method}_cr",
                f"{method}_reduced_statements",
                f"{method}_stmt_cr",
                f"{method}_invalid_rate",
                f"{method}_tests",
                f"{method}_time",
            ]
        )
    if "reducefix-sql-cleanup" in methods and "statement-ddmin" in methods:
        fields.extend(
            [
                "cleanup_minus_statement_cr",
                "cleanup_minus_statement_stmt_cr",
                "cleanup_minus_statement_tests",
                "cleanup_minus_statement_invalid_rate",
            ]
        )

    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields)
        writer.writeheader()
        for case_id in sorted(by_case):
            meta = case_meta[case_id]
            out = {
                "case_id": case_id,
                "bug_type": meta.get("bug_type", "unknown"),
                "original_bytes": meta.get("original_bytes", ""),
                "original_statements": meta.get("original_statements", ""),
            }
            for method in methods:
                row = by_case[case_id].get(method, {})
                out.update(
                    {
                        f"{method}_status": row.get("status", ""),
                        f"{method}_reduced_bytes": row.get("reduced_bytes", ""),
                        f"{method}_cr": row.get("compression_rate", ""),
                        f"{method}_reduced_statements": row.get("reduced_statements", ""),
                        f"{method}_stmt_cr": row.get("statement_compression_rate", ""),
                        f"{method}_invalid_rate": row.get("invalid_rate", ""),
                        f"{method}_tests": row.get("tests", ""),
                        f"{method}_time": row.get("elapsed_sec", ""),
                    }
                )
            cleanup = by_case[case_id].get("reducefix-sql-cleanup")
            statement = by_case[case_id].get("statement-ddmin")
            if cleanup and statement:
                out.update(
                    {
                        "cleanup_minus_statement_cr": metric(cleanup, "compression_rate")
                        - metric(statement, "compression_rate"),
                        "cleanup_minus_statement_stmt_cr": metric(cleanup, "statement_compression_rate")
                        - metric(statement, "statement_compression_rate"),
                        "cleanup_minus_statement_tests": metric(cleanup, "tests") - metric(statement, "tests"),
                        "cleanup_minus_statement_invalid_rate": metric(cleanup, "invalid_rate")
                        - metric(statement, "invalid_rate"),
                    }
                )
            writer.writerow(out)


def format_p(value: float) -> str:
    if value < 0.001:
        return f"{value:.2e}"
    return f"{value:.4f}"


def write_paper_table(summary: dict, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    lines = [
        "# SQLancer SQLite Main-Current DBMS Reduction Summary",
        "",
        "All rows below are computed on failure-preserving reductions; preservation is enforced by the oracle during reduction.",
        "",
        "| Method | Cases | Avg. CR (%) | Median CR (%) | Avg. reduced bytes | Median reduced bytes | Avg. reduced stmts | Median reduced stmts |",
        "|---|---:|---:|---:|---:|---:|---:|---:|",
    ]
    for method, item in summary["methods"].items():
        lines.append(
            "| {method} | {success} | {avg_cr:.2f} | {median_cr:.2f} | {avg_reduced_bytes:.1f} | {median_reduced_bytes:.1f} | {avg_reduced_statements:.1f} | {median_reduced_statements:.1f} |".format(
                method=method,
                **item,
            )
        )
    lines.extend(
        [
            "",
            "| Comparison | Metric | Mean delta | Better/Tie/Worse | one-sided sign p |",
            "|---|---|---:|---:|---:|",
        ]
    )
    for name, comp in summary["comparisons"].items():
        for metric_name in ("compression_rate", "statement_compression_rate"):
            item = comp[metric_name]
            lines.append(
                "| {name} | {metric} | {delta:.3f} | {better}/{tie}/{worse} | {p} |".format(
                    name=name,
                    metric=metric_name,
                    delta=item["mean_delta"],
                    better=item["better"],
                    tie=item["tie"],
                    worse=item["worse"],
                    p=format_p(item["one_sided_sign_p"]),
                )
            )
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser(description="Summarize DBMS SQL reduction results.")
    parser.add_argument("--results", required=True, help="JSONL result file.")
    parser.add_argument("--summary-json", default=None, help="Optional path for a detailed JSON summary.")
    parser.add_argument("--case-table-csv", default=None, help="Optional path for a per-case CSV table.")
    parser.add_argument("--paper-table-md", default=None, help="Optional path for a compact Markdown table.")
    args = parser.parse_args()

    results_path = Path(args.results)
    rows = read_jsonl(results_path)
    grouped: dict[str, list[dict]] = defaultdict(list)
    for row in rows:
        grouped[row.get("method", "<unknown>")].append(row)

    print("method,n,success,avg_cr,avg_stmt_cr,avg_invalid_rate,avg_tests,avg_time")
    for method in method_order(rows):
        items = grouped[method]
        successes = successful(items)
        print(
            ",".join(
                [
                    method,
                    str(len(items)),
                    str(len(successes)),
                    f"{mean([float(row.get('compression_rate', 0.0)) for row in successes]):.2f}",
                    f"{mean([float(row.get('statement_compression_rate', 0.0)) for row in successes]):.2f}",
                    f"{mean([float(row.get('invalid_rate', 0.0)) for row in successes]):.3f}",
                    f"{mean([float(row.get('tests', 0.0)) for row in successes]):.1f}",
                    f"{mean([float(row.get('elapsed_sec', 0.0)) for row in successes]):.2f}",
                ]
            )
        )
    summary = build_summary(rows, results_path)
    if args.summary_json:
        path = Path(args.summary_json)
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(summary, ensure_ascii=False, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    if args.case_table_csv:
        write_case_table(rows, Path(args.case_table_csv))
    if args.paper_table_md:
        write_paper_table(summary, Path(args.paper_table_md))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
