#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<long long> rows, cols, sums, diffs;
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        sums.insert(a + b);
        diffs.insert(a - b);
    }

    long long total = N * N;
    long long row_count = rows.size();
    long long col_count = cols.size();
    long long sum_count = sums.size();
    long long diff_count = diffs.size();

    total -= row_count * N;
    total -= col_count * N;
    total += row_count * col_count;

    for (long long s : sums) {
        long long min_i = max(1LL, s - N);
        long long max_i = min(N, s - 1);
        long long count = max_i - min_i + 1;
        total -= count;
    }

    for (long long d : diffs) {
        long long min_i = max(1LL, 1 - d);
        long long max_i = min(N, N - d);
        long long count = max_i - min_i + 1;
        total -= count;
    }

    for (long long a : rows) {
        for (long long s : sums) {
            long long b = s - a;
            if (cols.count(b)) {
                total++;
            }
        }
        for (long long d : diffs) {
            long long b = a - d;
            if (cols.count(b)) {
                total++;
            }
        }
    }

    for (long long b : cols) {
        for (long long s : sums) {
            long long a = s - b;
            if (rows.count(a)) {
                total++;
            }
        }
        for (long long d : diffs) {
            long long a = d + b;
            if (rows.count(a)) {
                total++;
            }
        }
    }

    for (long long s : sums) {
        for (long long d : diffs) {
            if ((s - d) % 2 == 0) {
                long long a = (s + d) / 2;
                long long b = (s - d) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N && rows.count(a) && cols.count(b)) {
                    total--;
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}