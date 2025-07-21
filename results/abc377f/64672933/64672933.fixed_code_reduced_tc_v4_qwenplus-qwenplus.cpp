#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<array<i64, 2>> placed;
    set<i64> rows, cols, diag1, diag2;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        placed.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Count how many unique cells are attacked
    i64 attacked = 0;

    // Attacked by rows
    attacked += rows.size() * N;

    // Attacked by columns
    attacked += cols.size() * N;

    // Attacked by diagonal 1: x + y = c
    for (auto d : diag1) {
        // Number of points on diagonal x + y = d
        i64 lo = max(1LL, d - N);
        i64 hi = min(N, d - 1);
        if (lo <= hi)
            attacked += hi - lo + 1;
    }

    // Attacked by diagonal 2: x - y = c
    for (auto d : diag2) {
        // x - y = d => x = y + d
        i64 lo = max(1LL, 1 - d);  // y >= 1, x <= N => y + d <= N => y <= N - d
        i64 hi = min(N, N - d);
        if (lo <= hi)
            attacked += hi - lo + 1;
    }

    // Remove over-counting: intersections between row & col, row & diag1, etc.

    // Remove overlap between row and column
    for (auto r : rows) {
        for (auto c : cols) {
            if (!placed.count({r, c})) {
                attacked--;
            }
        }
    }

    // Remove overlap between row and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (1 <= c && c <= N) {
                if (!placed.count({r, c})) {
                    attacked--;
                }
            }
        }
    }

    // Remove overlap between row and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (1 <= c && c <= N) {
                if (!placed.count({r, c})) {
                    attacked--;
                }
            }
        }
    }

    // Remove overlap between column and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (1 <= r && r <= N) {
                if (!placed.count({r, c})) {
                    attacked--;
                }
            }
        }
    }

    // Remove overlap between column and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = c + d;
            if (1 <= r && r <= N) {
                if (!placed.count({r, c})) {
                    attacked--;
                }
            }
        }
    }

    // Remove overlap between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 &&
                1 <= x && x <= N && 1 <= y && y <= N) {
                if (!placed.count({x, y})) {
                    attacked--;
                }
            }
        }
    }

    // Finally, remove overlap among all four
    for (auto p : placed) {
        i64 x = p[0], y = p[1];
        i64 d1 = x + y, d2 = x - y;
        if (rows.count(x) && cols.count(y) && diag1.count(d1) && diag2.count(d2)) {
            attacked--;  // This cell was counted in all four categories
        }
    }

    // Total valid positions
    i64 totalEmpty = N * N - (i64)placed.size();
    i64 safePositions = totalEmpty - attacked;

    cout << safePositions << "\n";

    return 0;
}