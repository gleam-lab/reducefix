#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> row_set, col_set, diag1_set, diag2_set;
    vector<array<i64, 2>> pieces(M);

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        row_set.insert(a);
        col_set.insert(b);
        diag1_set.insert(a + b);
        diag2_set.insert(a - b);
    }

    // Total squares under attack
    i64 attacked = 0;

    // Rows and columns
    attacked += (i64)row_set.size() * N;
    attacked += (i64)col_set.size() * N;

    // Diagonals: x + y = c
    for (auto c : diag1_set) {
        i64 y_min = max(1LL, c - N);
        i64 y_max = min(N, c - 1);
        attacked += y_max - y_min + 1;
    }

    // Anti-diagonals: x - y = d
    for (auto d : diag2_set) {
        if (d >= -(N-1) && d <= N-1) {
            i64 y_min = max(1LL, 1 - d);
            i64 y_max = min(N, N - d);
            if (y_min <= y_max)
                attacked += y_max - y_min + 1;
        }
    }

    // Subtract overlaps

    // Row-column intersections (pieces themselves)
    for (const auto& [a, b] : pieces) {
        bool in_row = row_set.count(a);
        bool in_col = col_set.count(b);
        if (in_row && in_col) {
            attacked -= 1;
        }
    }

    // Row-diagonal intersections
    for (const auto& [a, b] : pieces) {
        for (auto c : diag1_set) {
            if (a + b == c) {
                i64 y = c - a;
                if (1 <= y && y <= N) {
                    attacked -= 1;
                }
            }
        }
    }

    // Row-antidiagonal intersections
    for (const auto& [a, b] : pieces) {
        for (auto d : diag2_set) {
            if (a - b == d) {
                i64 y = a - d;
                if (1 <= y && y <= N) {
                    attacked -= 1;
                }
            }
        }
    }

    // Column-diagonal intersections
    for (const auto& [a, b] : pieces) {
        for (auto c : diag1_set) {
            if (a + b == c) {
                i64 x = c - b;
                if (1 <= x && x <= N) {
                    attacked -= 1;
                }
            }
        }
    }

    // Column-antidiagonal intersections
    for (const auto& [a, b] : pieces) {
        for (auto d : diag2_set) {
            if (a - b == d) {
                i64 x = b + d;
                if (1 <= x && x <= N) {
                    attacked -= 1;
                }
            }
        }
    }

    // Diagonal-antidiagonal intersections
    for (const auto& [a, b] : pieces) {
        for (auto c : diag1_set) {
            for (auto d : diag2_set) {
                i64 y = (c - d) / 2;
                i64 x = c - y;
                if ((c - d) % 2 == 0 && x == a && y == b) {
                    attacked -= 1;
                }
            }
        }
    }

    // Total empty non-attacked squares
    i64 total_empty = N * N - M;
    i64 result = total_empty - attacked;

    cout << result << "\n";

    return 0;
}