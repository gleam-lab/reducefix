#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> rows, cols, diag1, diag2;
    vector<array<i64, 2>> pieces(M);

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    // Total threatened positions
    i64 total_threatened = 0;

    // Count threats from rows
    total_threatened += rows.size() * N;

    // Count threats from columns
    total_threatened += cols.size() * N;

    // Count threats from diag1 (x + y = c)
    for (auto d : diag1) {
        i64 x_min = max(1LL, d - N);
        i64 x_max = min(N, d - 1);
        if (x_min <= x_max) {
            total_threatened += x_max - x_min + 1;
        }
    }

    // Count threats from diag2 (x - y = c)
    for (auto d : diag2) {
        i64 x_min = max(1LL, d + 1);
        i64 x_max = min(N, N + d);
        if (x_min <= x_max) {
            total_threatened += x_max - x_min + 1;
        }
    }

    // Now subtract overlaps

    // Overlap between rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 y = d - r;
            if (1 <= y && y <= N) {
                total_threatened--;
            }
        }
    }

    // Overlap between rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 y = r - d;
            if (1 <= y && y <= N) {
                total_threatened--;
            }
        }
    }

    // Overlap between columns and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 x = d - c;
            if (1 <= x && x <= N) {
                total_threatened--;
            }
        }
    }

    // Overlap between columns and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 x = c + d;
            if (1 <= x && x <= N) {
                total_threatened--;
            }
        }
    }

    // Overlap between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            i64 x = (d1 + d2);
            i64 y = (d1 - d2);
            if (x % 2 == 0 && y % 2 == 0) {
                x /= 2;
                y /= 2;
                if (1 <= x && x <= N && 1 <= y && y <= N) {
                    total_threatened--;
                }
            }
        }
    }

    // Finally, remove overlaps between all four categories:
    // Overlap between rows, columns, and intersections of diagonals
    for (auto [x, y] : pieces) {
        if (diag1.count(x + y) && diag2.count(x - y)) {
            total_threatened--; // already counted at intersection
        }
    }

    // Total number of squares minus threatened ones
    cout << N * N - total_threatened << "\n";

    return 0;
}