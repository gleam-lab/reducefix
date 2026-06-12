# ReduceFix DBMS SQL-Sequence Reduction

This directory implements the DBMS generalizability extension for ReduceFix.
It treats SQLancer-style reproducers as stateful input sequences and evaluates
whether a reducer can shrink them while preserving the same DBMS failure or
oracle mismatch.

## What This Adds

- `run_sql_reduction.py`: runs SQL reduction baselines and ReduceFix-SQL.
- `analyze_sql_reduction.py`: summarizes JSONL result files into compact tables.
- `manifests/*.jsonl`: experiment case manifests.
- `cases/*/original.sql`: SQL reproducer inputs.
- `results/*.jsonl`: generated experiment outputs.

## Supported Methods

- `line-ddmin`: classic ddmin over physical SQL lines.
- `statement-ddmin`: classic ddmin over parsed SQL statements.
- `reducefix-sql`: dependency-aware SQL sequence reducer that groups schema,
  data, and oracle statements before running ddmin.
- `reducefix-sql-cleanup`: two-stage reducer that first runs `reducefix-sql`
  to cross SQL validity barriers, then applies a generic statement-level
  cleanup pass to remove any dependencies that became redundant after the
  SQL-aware rewrite.
- `pure-llm`: optional external hook for a one-shot LLM SQL reduction baseline.
- `generated-reducer`: optional hook for an LLM-generated reducer exposing
  `generated_reduce_sql(input_sql, test_fn, verbose=True)`.
- `sqlancer-reducer`: optional external hook for SQLancer's reducer.
- `creduce`: optional external hook for C-Reduce-style command templates.

## Smoke Test

```bash
python3 dbms_results/run_sql_reduction.py \
  --manifest dbms_results/manifests/smoke_sqlite.jsonl \
  --methods reducefix-sql \
  --out /tmp/reducefix_dbms_prompt_check.jsonl \
  --emit-prompts-dir dbms_results/results/smoke_prompts

python3 dbms_results/run_sql_reduction.py \
  --manifest dbms_results/manifests/smoke_sqlite.jsonl \
  --methods line-ddmin statement-ddmin reducefix-sql \
  --out dbms_results/results/smoke_sqlite_results.jsonl \
  --verbose

python3 dbms_results/analyze_sql_reduction.py \
  --results dbms_results/results/smoke_sqlite_results.jsonl \
  --summary-json dbms_results/results/smoke_sqlite_summary.json \
  --case-table-csv dbms_results/results/smoke_sqlite_case_table.csv \
  --paper-table-md dbms_results/results/smoke_sqlite_paper_table.md
```

External reducers are configured with command templates. The command must read
`{input}` and write the reduced SQL to `{output}`:

```bash
python3 dbms_results/run_sql_reduction.py \
  --manifest real_sqlancer_cases.jsonl \
  --methods statement-ddmin reducefix-sql pure-llm sqlancer-reducer creduce \
  --pure-llm-command 'python3 call_llm_sql_reducer.py --input {input} --output {output}' \
  --sqlancer-reducer-command 'java -jar sqlancer.jar --use-reducer ... --input {input} --output {output}' \
  --creduce-command 'creduce interesting.sh {input}; cp {input} {output}' \
  --out dbms_results/results/real_sqlancer_results.jsonl
```

The smoke fixture is intentionally small and deterministic. For the paper
experiment, replace it with real SQLancer failure reproducers and fixed DBMS
versions in the manifest.

## Import SQLancer Failure Snippets

The SQLancer `bugs.json` repository stores reduced failure-report snippets rather
than raw fuzzer logs. The importer below creates a small real-data smoke
manifest from selected SQLite snippets and records the oracle observed on the
current `sqlite3` binary. It strips report comments from executable SQL and
preserves the original test lines in per-case metadata:

```bash
python3 dbms_results/import_sqlancer_failure_snippets.py

python3 dbms_results/run_sql_reduction.py \
  --manifest dbms_results/manifests/sqlancer_sqlite_real_smoke.jsonl \
  --methods line-ddmin statement-ddmin reducefix-sql \
  --out dbms_results/results/sqlancer_sqlite_real_smoke_results.jsonl \
  --output-sql-dir dbms_results/results/sqlancer_sqlite_real_smoke_sql

python3 dbms_results/analyze_sql_reduction.py \
  --results dbms_results/results/sqlancer_sqlite_real_smoke_results.jsonl
```

These cases are useful for checking the harness on real SQLancer reports. For a
full paper experiment, use unreduced SQLancer logs or version-pinned historical
DBMS builds so the oracle is the original failure signature.

## Prepare Main SQLite Dataset

The main data-preparation script scans SQLancer `bugs.json`, replays SQLite
tests on the current `sqlite3` binary three times, and emits objective manifests:

```bash
python3 dbms_results/prepare_sqlancer_main_dataset.py \
  --bugs-json /tmp/sqlancer_bugs.json
```

Default selection rule:

- DBMS is SQLite.
- SQLancer status is `fixed`.
- The normalized SQL snippet is stable and observable across three local replays.
- Normalized SQL has at least 100 bytes and at least 3 SQL statements.

Outputs:

- `dbms_results/manifests/sqlancer_sqlite_candidate_index.jsonl`
- `dbms_results/manifests/sqlancer_sqlite_fixed_observable_all.jsonl`
- `dbms_results/manifests/sqlancer_sqlite_main_current.jsonl`
- `dbms_results/manifests/sqlancer_sqlite_main_current_summary.json`

Run the prepared main manifest with:

```bash
bash dbms_results/run_sqlancer_sqlite_main_current.sh
```

Override budgets when needed:

```bash
MAX_TIME_SEC=120 TIMEOUT_SEC=5 bash dbms_results/run_sqlancer_sqlite_main_current.sh
```

The current paper DBMS comparison uses statement-level `ddmin` as the SQL
baseline and includes the optimized cleanup variant:

```bash
python3 dbms_results/run_sql_reduction.py \
  --manifest dbms_results/manifests/sqlancer_sqlite_main_current.jsonl \
  --methods statement-ddmin reducefix-sql reducefix-sql-cleanup \
  --out dbms_results/results/sqlancer_sqlite_main_current_cleanup_results.jsonl \
  --output-sql-dir dbms_results/results/sqlancer_sqlite_main_current_cleanup_sql \
  --max-time-sec 60 \
  --timeout-sec 5

python3 dbms_results/analyze_sql_reduction.py \
  --results dbms_results/results/sqlancer_sqlite_main_current_cleanup_results.jsonl \
  --summary-json dbms_results/results/sqlancer_sqlite_main_current_cleanup_summary.json \
  --case-table-csv dbms_results/results/sqlancer_sqlite_main_current_cleanup_case_table.csv \
  --paper-table-md dbms_results/results/sqlancer_sqlite_main_current_cleanup_paper_table.md
```

Current main-result snapshot on 78 stable SQLite SQLancer cases. All rows are
conditioned on the reduced SQL preserving the same observed failure; this is a
harness requirement rather than an evaluated advantage.

| Reducer | Cases | Avg. CR (%) | Median CR (%) | Avg. reduced bytes | Avg. reduced statements |
|---|---:|---:|---:|---:|---:|
| statement-ddmin | 78 | 14.48 | 1.42 | 160.2 | 3.6 |
| reducefix-sql | 78 | 13.66 | 2.24 | 161.2 | 3.8 |
| reducefix-sql-cleanup | 78 | 16.57 | 7.74 | 155.2 | 3.6 |

Against `statement-ddmin`, `reducefix-sql-cleanup` improves average byte
compression rate by 2.09 percentage points with a one-sided sign-test
`p=0.0065`. The vanilla `reducefix-sql` variant is useful for mechanism
analysis because it substantially reduces invalid intermediate candidates and
oracle calls, but these process-cost metrics should not be the main DBMS
headline.

## Manifest Schema

Each JSONL row describes one SQL reproducer:

```json
{
  "case_id": "sqlite_stateful_dependency",
  "dbms": "sqlite",
  "input_sql": "dbms_results/cases/sqlite_stateful_dependency/original.sql",
  "bug_type": "logic",
  "oracle": {
    "stdout_contains": "needle",
    "exit_code": 0,
    "forbid_stderr_contains": ["no such table", "syntax error"]
  }
}
```

For SQLancer failure studies, set `oracle` to the observed failure signature: a
crash stderr substring, a non-zero exit code, or an oracle-mismatch output.
