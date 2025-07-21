#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    set<pair<i64, i64>> occupied;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }

    i64 attacked = 0;

    // Squares attacked by rows
    attacked += rows.size() * N;

    // Squares attacked by columns
    attacked += cols.size() * N;

    // Subtract intersections where rows and columns overlap
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c}) == 0) {
                row_col_intersect++;
            }
        }
    }
    attacked -= row_col_intersect;

    // Squares attacked by diag1 (i + j = k)
    for (auto k : diag1) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_min > x_max) continue;
        attacked += (x_max - x_min + 1);
    }

    // Squares attacked by diag2 (i - j = k)
    for (auto k : diag2) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_min > x_max) continue;
        attacked += (x_max - x_min + 1);
    }

    // Subtract intersections between rows and diag1
    for (auto r : rows) {
        for (auto k : diag1) {
            i64 j = k - r;
            if (j >= 1 && j <= N) {
                if (occupied.count({r, j}) == 0) {
                    attacked--;
                }
            }
        }
    }

    // Subtract intersections between rows and diag2
    for (auto r : rows) {
        for (auto k : diag2) {
            i64 j = r - k;
            if (j >= 1 && j <= N) {
                if (occupied.count({r, j}) == 0) {
                    attacked--;
                }
            }
        }
    }

    // Subtract intersections between cols and diag1
    for (auto c : cols) {
        for (auto k : diag1) {
            i64 i = k - c;
            if (i >= 1 && i <= N) {
                if (occupied.count({i, c}) == 0) {
                    attacked--;
                }
            }
        }
    }

    // Subtract intersections between cols and diag2
    for (auto c : cols) {
        for (auto k : diag2) {
            i64 i = c + k;
            if (i >= 1 && i <= N) {
                if (occupied.count({i, c}) == 0) {
                    attacked--;
                }
            }
        }
    }

    // Add back the squares counted in all four sets (rows, cols, diag1, diag2)
    // These are the squares (i,j) where:
    // i is in rows, j is in cols, i+j is in diag1, and i-j is in diag2
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                if (occupied.count({r, c}) == 0) {
                    attacked++;
                }
            }
        }
    }

    // The total safe squares is N*N - attacked - M (since M squares are already occupied)
    i64 total_safe = N * N - attacked - M;
    cout << max(0LL, total_safe) << "\n";

    return 0;
}