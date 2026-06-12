CREATE TABLE test (c0);
CREATE INDEX index_0 ON test(c0 LIKE '');
PRAGMA case_sensitive_like=false;
VACUUM;
SELECT * from test;
