#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;
    vector<array<i64, 2>> pieces;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.push_back({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares attacked by existing pieces
    i64 attacked = 0;

    // Count all cells in attacked rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;

    // Remove overcounts from intersections of rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            // (r,c) was counted twice
            attacked -= 1;
        }
    }

    // Count all cells on diagonals (sum)
    for (auto d : diag1) {
        i64 lo = max(1LL, d - N);
        i64 hi = min(N, d - 1);
        if (lo <= hi) {
            attacked += hi - lo + 1;
        }
    }

    // Remove overcounts with rows and columns
    for (auto d : diag1) {
        for (auto r : rows) {
            i64 c = d - r;
            if (1 <= c && c <= N) {
                attacked -= 1;
            }
        }
        for (auto c : cols) {
            i64 r = d - c;
            if (1 <= r && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Count all cells on anti-diagonals (diff)
    for (auto d : diag2) {
        i64 lo = max(1LL, 1 + d);
        i64 hi = min(N, N + d);
        if (lo <= hi) {
            attacked += hi - lo + 1;
        }
    }

    // Remove overcounts with rows and columns
    for (auto d : diag2) {
        for (auto r : rows) {
            i64 c = r - d;
            if (1 <= c && c <= N) {
                attacked -= 1;
            }
        }
        for (auto c : cols) {
            i64 r = c + d;
            if (1 <= r && r <= N) {
                attacked -= 1;
            }
        }
    }

    // Remove overcounts between sum and difference diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            // Solve x + y = d1 and x - y = d2
            if ((d1 + d2) % 2 == 0) {
                i64 x = (d1 + d2) / 2;
                i64 y = d1 - x;
                if (1 <= x && x <= N && 1 <= y && y <= N) {
                    attacked -= 1;
                }
            }
        }
    }

    // Now subtract the attacked positions that are occupied
    i64 occupiedAttacked = 0;
    for (auto [x, y] : pieces) {
        if (rows.count(x) || cols.count(y) || diag1.count(x + y) || diag2.count(x - y)) {
            occupiedAttacked += 1;
        }
    }

    i64 totalEmpty = N * N - M;
    i64 answer = totalEmpty - (attacked - occupiedAttacked);

    cout << max(0LL, answer) << "\n";

    return 0;
}