#include <bits/stdc++.h>

using namespace std;

const int MAX_M = 2000;

long long N;
int M;

set<long long> rows, cols;
set<pair<long long, long long>> diag1, diag2;

vector<long long> rowv, colv;
vector<pair<long long, long long>> d1v, d2v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;

        rows.insert(a);
        cols.insert(b);
        diag1.insert({a + b, a});
        diag2.insert({a - b, a});

        rowv.push_back(a);
        colv.push_back(b);
        d1v.emplace_back(a + b, a);
        d2v.emplace_back(a - b, a);
    }

    // Total squares
    long long total = N * N;

    // Subtract all occupied squares
    total -= M;

    // For each row with a piece, the entire row is invalid
    long long bad_rows = rows.size();
    // For each column with a piece, the entire column is invalid
    long long bad_cols = cols.size();

    // For each diagonal of type x+y=k, it invalidates N - |k - (N+1)| squares
    set<long long> d1keys;
    for (auto p : diag1) d1keys.insert(p.first);
    long long bad_d1 = d1keys.size();

    // For each diagonal of type x-y=k, it invalidates N - |k - (N+1)| squares
    set<long long> d2keys;
    for (auto p : diag2) d2keys.insert(p.first);
    long long bad_d2 = d2keys.size();

    // Inclusion-exclusion

    // Subtract row and column invalidated cells
    long long ans = total - (bad_rows * N + bad_cols * N);

    // Subtract diagonal invalidated cells
    for (long long s : d1keys) {
        long long len = min(s, 2 * N - s + 1);
        ans -= len;
    }
    for (long long d : d2keys) {
        long long len = min(N + d, N - d + 1);
        if (d < 0) len = min(N + d + 1, N - d);
        ans -= len;
    }

    // Add back intersections: row-col
    ans += bad_rows * bad_cols;

    // Add back intersections: row-diag1, row-diag2
    for (long long r : rowv) {
        for (auto s : d1keys) {
            if (s >= r + 1 && s <= r + N) {
                ans++;
            }
        }
        for (auto d : d2keys) {
            long long c = r - d;
            if (c >= 1 && c <= N) {
                ans++;
            }
        }
    }

    // Add back intersections: col-diag1, col-diag2
    for (long long c : colv) {
        for (auto s : d1keys) {
            long long r = s - c;
            if (r >= 1 && r <= N) {
                ans++;
            }
        }
        for (auto d : d2keys) {
            long long r = d + c;
            if (r >= 1 && r <= N) {
                ans++;
            }
        }
    }

    // Add back intersections: diag1-diag2
    for (auto p1 : d1v) {
        for (auto p2 : d2v) {
            long long s = p1.first, d = p2.first;
            long long x = (s + d) / 2;
            long long y = (s - d) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                ans++;
            }
        }
    }

    // Subtract triple overlaps: row-col-diag1, row-col-diag2
    for (long long r : rowv) {
        for (long long c : colv) {
            long long s = r + c;
            if (d1keys.count(s)) ans--;
            long long d = r - c;
            if (d2keys.count(d)) ans--;
        }
    }

    // Subtract triple overlaps: row-diag1-diag2, col-diag1-diag2
    for (long long r : rowv) {
        for (auto p : d2keys) {
            long long c = r - p;
            long long s = r + c;
            if (d1keys.count(s)) ans--;
        }
    }
    for (long long c : colv) {
        for (auto p : d2keys) {
            long long r = p + c;
            long long s = r + c;
            if (d1keys.count(s)) ans--;
        }
    }

    // Add back quadruple overlap
    for (long long r : rowv) {
        for (long long c : colv) {
            long long s = r + c;
            long long d = r - c;
            if (d1keys.count(s) && d2keys.count(d)) ans++;
        }
    }

    cout << max(0LL, ans) << endl;

    return 0;
}