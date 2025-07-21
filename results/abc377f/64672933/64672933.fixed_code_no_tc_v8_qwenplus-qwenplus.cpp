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

    // Total squares covered by existing pieces' attack lines
    set<pair<i64, i64>> attacked;

    // Add all squares in the same row
    for (auto r : rows) {
        for (i64 j = 1; j <= N; ++j) {
            if (!pieces.count({r, j})) {
                attacked.insert({r, j});
            }
        }
    }

    // Add all squares in the same column
    for (auto c : cols) {
        for (i64 i = 1; i <= N; ++i) {
            if (!pieces.count({i, c})) {
                attacked.insert({i, c});
            }
        }
    }

    // Add all squares on diagonal 1: x + y = k
    for (auto d : diag1) {
        // Solve x + y = d for 1 <= x,y <= N
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        for (i64 x = min_x; x <= max_x; ++x) {
            i64 y = d - x;
            if (!pieces.count({x, y})) {
                attacked.insert({x, y});
            }
        }
    }

    // Add all squares on diagonal 2: x - y = k => x = y + k
    for (auto d : diag2) {
        // Solve x - y = d => x = y + d
        i64 min_y = max(1LL, 1 - d);
        i64 max_y = min(N, N - d);
        for (i64 y = min_y; y <= max_y; ++y) {
            i64 x = y + d;
            if (!pieces.count({x, y})) {
                attacked.insert({x, y});
            }
        }
    }

    // Subtract overlapping attacked cells that were counted more than once
    // and also remove those counted at intersection of two lines
    set<pair<i64, i64>> overcounted;

    // Check intersections between row & col
    for (auto r : rows) {
        for (auto c : cols) {
            if (!pieces.count({r, c})) {
                overcounted.insert({r, c});
            }
        }
    }

    // Check intersections between row & diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 y = d - r;
            if (1 <= y && y <= N && !pieces.count({r, y})) {
                overcounted.insert({r, y});
            }
        }
    }

    // Check intersections between row & diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 y = r - d;
            if (1 <= y && y <= N && !pieces.count({r, y})) {
                overcounted.insert({r, y});
            }
        }
    }

    // Check intersections between col & diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 x = d - c;
            if (1 <= x && x <= N && !pieces.count({x, c})) {
                overcounted.insert({x, c});
            }
        }
    }

    // Check intersections between col & diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 x = d + c;
            if (1 <= x && x <= N && !pieces.count({x, c})) {
                overcounted.insert({x, c});
            }
        }
    }

    // Check intersections between diag1 & diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 &&
                1 <= x && x <= N && 1 <= y && y <= N &&
                !pieces.count({x, y})) {
                overcounted.insert({x, y});
            }
        }
    }

    // Now calculate total valid positions
    i64 total_attacked = attacked.size();
    i64 overcounted_twice = overcounted.size();

    // Inclusion-Exclusion: subtract total attacked, add back overcounted
    i64 total_squares = N * N;
    i64 used_squares = M;
    i64 safe_squares = total_squares - used_squares - total_attacked + overcounted_twice;

    cout << safe_squares << "\n";

    return 0;
}