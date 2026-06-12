# SQLancer SQLite DBMS Case Notes

These notes identify candidate cases for a DBMS generalizability subsection or
case study. Metrics come from
`sqlancer_sqlite_main_current_cleanup_case_table.csv`.

## High-Delta Cases

| Case | Oracle type | Original bytes/statements | statement-ddmin CR | reducefix-sql-cleanup CR | Delta |
|---|---|---:|---:|---:|---:|
| `sqlancer_sqlite_102_query_with_order_by_results_in_database_disk_image_is_malformed` | error | 204 / 5 | 0.00 | 31.86 | +31.86 |
| `sqlancer_sqlite_117_distinct_malfunctions_for_is_null` | PQS | 277 / 5 | 4.33 | 33.21 | +28.88 |
| `sqlancer_sqlite_104_query_with_distinct_does_not_fetch_all_distinct_rows` | PQS | 305 / 7 | 3.93 | 29.51 | +25.57 |
| `sqlancer_sqlite_309_max_yields_unexpected_result_for_utf_16` | TLP aggregate | 171 / 5 | 0.00 | 21.64 | +21.64 |
| `sqlancer_sqlite_48_built_in_rtrim_collating_sequence_yields_incorrect_comparisons` | PQS | 179 / 3 | 0.00 | 16.20 | +16.20 |
| `sqlancer_sqlite_103_analyze_causes_distinct_to_malfunction_in_cross_join` | PQS | 317 / 7 | 2.84 | 18.93 | +16.09 |

## Case 102: Schema Object Cleanup After Value Reduction

Original SQL:

```sql
CREATE TABLE t0 (c0 REAL, c1);
CREATE UNIQUE INDEX i0 ON t0(c1, 0 | c0);
INSERT INTO t0(c0) VALUES (4750228396194493326), (0);
UPDATE OR REPLACE t0 SET c0 = 'a', c1 = '';
SELECT * FROM t0 ORDER BY t0.c1;
```

`statement-ddmin` keeps all five statements because dropping the wrong schema or
state statement tends to break the reproducer instead of preserving the same
oracle. `reducefix-sql` first reduces the multi-row insert to one tuple while
keeping the table, mutation, and final query dependencies valid. The cleanup
stage then proves that the unique index is no longer needed and removes it:

```sql
CREATE TABLE t0 (c0 REAL, c1);
INSERT INTO t0(c0) VALUES (0);
UPDATE OR REPLACE t0 SET c0 = 'a', c1 = '';
SELECT * FROM t0 ORDER BY t0.c1;
```

This illustrates the two-stage mechanism: SQL-aware reduction can safely make a
state-preserving rewrite that exposes a later generic cleanup opportunity.

## Case 117: Tuple-Level Data Reduction

Original SQL contains eleven repeated `NULL` tuples plus one string tuple before
a `DISTINCT` predicate oracle:

```sql
CREATE TABLE t0 (c0, c1 NOT NULL DEFAULT 1, c2, PRIMARY KEY (c0, c1));
INSERT INTO t0(c2) VALUES (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL);
INSERT INTO t0(c2) VALUES ('a');
ANALYZE t0;
SELECT DISTINCT * FROM t0 WHERE NULL IS t0.c0;
```

`statement-ddmin` can remove `ANALYZE`, but it cannot shrink the large
multi-value insert because the insert is one statement-level unit. The SQL-aware
pass splits the `VALUES` tuple list and keeps only the single tuple required by
the oracle:

```sql
CREATE TABLE t0 (c0, c1 NOT NULL DEFAULT 1, c2, PRIMARY KEY (c0, c1));
INSERT INTO t0(c2) VALUES (NULL);
INSERT INTO t0(c2) VALUES ('a');
SELECT DISTINCT * FROM t0 WHERE NULL IS t0.c0;
```

This is the most direct evidence that DBMS inputs need structure-aware units:
the useful reduction boundary is inside a SQL statement, not only between SQL
statements.
