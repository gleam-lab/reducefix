CREATE TABLE t0(c0 INTEGER PRIMARY KEY);
INSERT INTO t0(c0) VALUES (1);
PRAGMA reverse_unordered_selects=true;
SELECT * FROM t0 WHERE ((t0.c0 > 'a') OR (t0.c0 <= 'a'));
SELECT ((t0.c0 > 'a') OR (t0.c0 <= 'a')) FROM t0;
