#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<pair<i64, i64>> pieces;
    set<i64> rows, cols, diag1, diag2;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares attacked by existing pieces
    set<pair<i64, i64>> attacked;

    // Attack along rows
    for (i64 r : rows) {
        for (i64 c = 1; c <= N; ++c) {
            attacked.insert({r, c});
        }
    }

    // Attack along columns
    for (i64 c : cols) {
        for (i64 r = 1; r <= N; ++r) {
            attacked.insert({r, c});
        }
    }

    // Attack along diagonal 1: x + y = constant
    for (i64 d : diag1) {
        // Compute range of x
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        for (i64 x = min_x; x <= max_x; ++x) {
            i64 y = d - x;
            if (y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // Attack along diagonal 2: x - y = constant
    for (i64 d : diag2) {
        // For x - y = d, rewrite as x = y + d
        i64 min_y = max(1LL, 1 - d);
        i64 max_y = min(N, N - d);
        for (i64 y = min_y; y <= max_y; ++y) {
            i64 x = y + d;
            if (x >= 1 && x <= N) {
                attacked.insert({x, y});
            }
        }
    }

    // Count valid positions
    i64 count = 0;
    for (auto pos : attacked) {
        if (!pieces.count(pos)) {
            count++;
        }
    }

    i64 total_empty = N * N - M;
    cout << max(0LL, total_empty - count) << "\n";

    return 0;
}