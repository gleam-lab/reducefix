#!/usr/bin/env bash
set -euo pipefail

METHODS=${METHODS:-"line-ddmin statement-ddmin reducefix-sql reducefix-sql-cleanup"}
RESULTS=${RESULTS:-dbms_results/results/sqlancer_sqlite_main_current_cleanup_results.jsonl}
SQL_DIR=${SQL_DIR:-dbms_results/results/sqlancer_sqlite_main_current_cleanup_sql}
SUMMARY_JSON=${SUMMARY_JSON:-dbms_results/results/sqlancer_sqlite_main_current_cleanup_summary.json}
CASE_TABLE_CSV=${CASE_TABLE_CSV:-dbms_results/results/sqlancer_sqlite_main_current_cleanup_case_table.csv}
PAPER_TABLE_MD=${PAPER_TABLE_MD:-dbms_results/results/sqlancer_sqlite_main_current_cleanup_paper_table.md}

# shellcheck disable=SC2086
python3 dbms_results/run_sql_reduction.py \
  --manifest dbms_results/manifests/sqlancer_sqlite_main_current.jsonl \
  --methods ${METHODS} \
  --out "${RESULTS}" \
  --output-sql-dir "${SQL_DIR}" \
  --max-time-sec "${MAX_TIME_SEC:-60}" \
  --timeout-sec "${TIMEOUT_SEC:-5}"

python3 dbms_results/analyze_sql_reduction.py \
  --results "${RESULTS}" \
  --summary-json "${SUMMARY_JSON}" \
  --case-table-csv "${CASE_TABLE_CSV}" \
  --paper-table-md "${PAPER_TABLE_MD}"
