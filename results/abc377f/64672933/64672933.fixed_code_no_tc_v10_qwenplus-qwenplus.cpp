#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> pieces;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total squares under attack from existing pieces
    set<i64> attacked_rows = rows;
    set<i64> attacked_cols = cols;
    set<i64> attacked_diag1 = diag1;
    set<i64> attacked_diag2 = diag2;

    i64 total_attacked = 0;

    // Count all squares attacked by row or column
    total_attacked += 1LL * attacked_rows.size() * N;
    total_attacked += 1LL * attacked_cols.size() * N;

    // Count all squares attacked by diagonal 1 (a+b)
    for (auto d : attacked_diag1) {
        i64 x_min = max(1LL, d - N);
        i64 x_max = min(N, d - 1);
        if (x_min <= x_max) {
            total_attacked += x_max - x_min + 1;
        }
    }

    // Count all squares attacked by diagonal 2 (a-b)
    for (auto d : attacked_diag2) {
        i64 x_min = max(1LL, d + 1);
        i64 x_max = min(N, N + d);
        if (x_min <= x_max) {
            total_attacked += x_max - x_min + 1;
        }
    }

    // Subtract overcounted intersections between rows and columns
    for (auto r : attacked_rows) {
        for (auto c : attacked_cols) {
            if (pieces.count({r, c}) == 0) {
                // Already counted in row/column but not a piece
                total_attacked -= 1;
            }
        }
    }

    // Subtract overcounted intersections between row/col and diagonals
    auto count_intersection = [&](i64 a, i64 b) {
        return (diag1.count(a + b) || diag2.count(a - b));
    };

    for (auto r : attacked_rows) {
        for (auto d1 : attacked_diag1) {
            i64 c = d1 - r;
            if (1 <= c && c <= N && !pieces.count({r, c})) {
                if (diag2.count(r - c)) {
                    total_attacked -= 1;
                }
            }
        }
    }

    for (auto c : attacked_cols) {
        for (auto d1 : attacked_diag1) {
            i64 r = d1 - c;
            if (1 <= r && r <= N && !pieces.count({r, c})) {
                if (diag2.count(r - c)) {
                    total_attacked -= 1;
                }
            }
        }
    }

    for (auto r : attacked_rows) {
        for (auto d2 : attacked_diag2) {
            i64 c = r - d2;
            if (1 <= c && c <= N && !pieces.count({r, c})) {
                if (diag1.count(r + c)) {
                    total_attacked -= 1;
                }
            }
        }
    }

    for (auto c : attacked_cols) {
        for (auto d2 : attacked_diag2) {
            i64 r = c + d2;
            if (1 <= r && r <= N && !pieces.count({r, c})) {
                if (diag1.count(r + c)) {
                    total_attacked -= 1;
                }
            }
        }
    }

    // Subtract overcounted intersections between diagonals
    for (auto d1 : attacked_diag1) {
        for (auto d2 : attacked_diag2) {
            i64 x = (d1 + d2);
            if (x % 2 == 0) {
                x /= 2;
                i64 y = d1 - x;
                if (1 <= x && x <= N && 1 <= y && y <= N && !pieces.count({x, y})) {
                    total_attacked -= 1;
                }
            }
        }
    }

    // Final result
    i64 total_empty = N * N - M;
    i64 safe_squares = total_empty - total_attacked;

    cout << safe_squares << "\n";

    return 0;
}