#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N;
    int M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares covered by all lines
    i64 total_covered = 0;

    // Row coverage: N per row
    total_covered += (i64)rows.size() * N;

    // Column coverage: N per column
    total_covered += (i64)cols.size() * N;

    // Diagonal \ (a+b=k): length of diagonal varies
    for (auto s : diag1) {
        i64 lo = max(1LL, s - N);
        i64 hi = min(N, s - 1);
        total_covered += hi - lo + 1;
    }

    // Diagonal / (a-b=k): length of diagonal varies
    for (auto k : diag2) {
        // x - y = k => x = y + k
        i64 lo = max(1LL, 1 - k);
        i64 hi = min(N, N - k);
        if (hi >= lo)
            total_covered += hi - lo + 1;
    }

    // Inclusion-Exclusion Principle to remove overlaps

    // Rows x Columns
    total_covered -= (i64)rows.size() * cols.size();

    // Rows x Diag \
    for (auto r : rows) {
        for (auto s : diag1) {
            i64 c = s - r;
            if (1 <= c && c <= N)
                total_covered--;
        }
    }

    // Rows x Diag /
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (1 <= c && c <= N)
                total_covered--;
        }
    }

    // Cols x Diag \
    for (auto c : cols) {
        for (auto s : diag1) {
            i64 r = s - c;
            if (1 <= r && r <= N)
                total_covered--;
        }
    }

    // Cols x Diag /
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (1 <= r && r <= N)
                total_covered--;
        }
    }

    // Diag \ x Diag /
    for (auto s : diag1) {
        for (auto d : diag2) {
            // Solve:
            // r + c = s
            // r - c = d
            // => 2r = s + d => r = (s + d)/2
            // => 2c = s - d => c = (s - d)/2
            if ((s + d) % 2 == 0) {
                i64 r = (s + d) / 2;
                i64 c = (s - d) / 2;
                if (1 <= r && r <= N && 1 <= c && c <= N)
                    total_covered--;
            }
        }
    }

    // Rows x Cols x Diag \ already counted
    // Rows x Cols x Diag / already counted
    // All triple overlaps are removed in previous steps

    // Subtract full overlap count where all four sets intersect
    for (auto r : rows) {
        for (auto c : cols) {
            i64 s = r + c;
            i64 d = r - c;
            if (diag1.count(s) && diag2.count(d))
                total_covered++;
        }
    }

    i64 total_empty = N * N - total_covered;

    cout << total_empty << "\n";

    return 0;
}