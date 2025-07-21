#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> pieces(M);
    set<i64> rows, cols, diag_sum, diag_diff;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag_sum.insert(a + b);
        diag_diff.insert(a - b);
    }

    i64 dangerous = 0;

    // Count rows and columns
    dangerous += rows.size() * N;
    dangerous += cols.size() * N;
    dangerous -= rows.size() * cols.size(); // intersection of rows and cols

    // Count diagonals (sum and diff)
    for (auto s : diag_sum) {
        i64 x_plus_y = s;
        i64 min_x = max(1LL, x_plus_y - N);
        i64 max_x = min(N, x_plus_y - 1);
        if (max_x >= min_x) {
            dangerous += (max_x - min_x + 1);
        }
    }
    for (auto d : diag_diff) {
        i64 x_minus_y = d;
        i64 min_x = max(1LL, 1 + x_minus_y);
        i64 max_x = min(N, N + x_minus_y);
        if (max_x >= min_x) {
            dangerous += (max_x - min_x + 1);
        }
    }

    // Subtract intersections between diagonals and rows/columns
    for (auto s : diag_sum) {
        for (auto r : rows) {
            // r + y = s => y = s - r
            i64 y = s - r;
            if (y >= 1 && y <= N) {
                dangerous--;
            }
        }
        for (auto c : cols) {
            // x + c = s => x = s - c
            i64 x = s - c;
            if (x >= 1 && x <= N) {
                dangerous--;
            }
        }
    }
    for (auto d : diag_diff) {
        for (auto r : rows) {
            // r - y = d => y = r - d
            i64 y = r - d;
            if (y >= 1 && y <= N) {
                dangerous--;
            }
        }
        for (auto c : cols) {
            // x - c = d => x = c + d
            i64 x = c + d;
            if (x >= 1 && x <= N) {
                dangerous--;
            }
        }
    }

    // Add back squares counted twice in diagonals (sum and diff)
    for (auto s : diag_sum) {
        for (auto d : diag_diff) {
            // x + y = s, x - y = d => x = (s + d)/2, y = (s - d)/2
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0) {
                i64 x = (s + d) / 2;
                i64 y = (s - d) / 2;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    dangerous++;
                }
            }
        }
    }

    // Total safe squares = N^2 - dangerous - M (since the existing pieces are already placed)
    i64 safe = N * N - dangerous - M;
    cout << safe << "\n";

    return 0;
}