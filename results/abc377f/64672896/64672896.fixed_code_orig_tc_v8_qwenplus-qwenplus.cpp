#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;

    set<i64> row_set, col_set, diag1_set, diag2_set;
    set<pair<i64, i64>> piece_set;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        row_set.insert(a);
        col_set.insert(b);
        diag1_set.insert(a + b);
        diag2_set.insert(a - b);
        piece_set.emplace(a, b);
    }

    // Total squares under attack
    i64 attacked = 0;

    // Rows and columns: O(M)
    attacked += row_set.size() * N;
    attacked += col_set.size() * N;

    // Diagonals: O(M^2)
    for (auto d1 : diag1_set) {
        for (auto d2 : diag2_set) {
            // Find intersection point of diagonals
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked += 1;
            }
        }
    }

    // Remove overlaps between rows and columns
    for (auto r : row_set) {
        for (auto c : col_set) {
            if (piece_set.count({r, c}) == 0) {
                attacked -= 1; // Not a piece, was double-counted
            }
        }
    }

    // Remove overlaps between rows and diag1
    for (auto r : row_set) {
        for (auto d : diag1_set) {
            i64 y = d - r;
            if (y >= 1 && y <= N) {
                attacked -= 1;
            }
        }
    }

    // Remove overlaps between rows and diag2
    for (auto r : row_set) {
        for (auto d : diag2_set) {
            i64 y = r - d;
            if (y >= 1 && y <= N) {
                attacked -= 1;
            }
        }
    }

    // Remove overlaps between cols and diag1
    for (auto c : col_set) {
        for (auto d : diag1_set) {
            i64 x = d - c;
            if (x >= 1 && x <= N) {
                attacked -= 1;
            }
        }
    }

    // Remove overlaps between cols and diag2
    for (auto c : col_set) {
        for (auto d : diag2_set) {
            i64 x = d + c;
            if (x >= 1 && x <= N) {
                attacked -= 1;
            }
        }
    }

    // Add back overlaps among three types that were subtracted too many times
    for (auto d1 : diag1_set) {
        for (auto d2 : diag2_set) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (row_set.count(x)) attacked += 1;
                if (col_set.count(y)) attacked += 1;
            }
        }
    }

    // Subtract overlaps among all four types
    for (auto r : row_set) {
        for (auto c : col_set) {
            i64 d1 = r + c;
            i64 d2 = r - c;
            if (diag1_set.count(d1) && diag2_set.count(d2)) {
                attacked -= 1;
            }
        }
    }

    i64 total_squares = N * N;
    i64 occupied = M;
    i64 answer = total_squares - occupied - attacked;
    cout << max(0LL, answer) << "\n";

    return 0;
}