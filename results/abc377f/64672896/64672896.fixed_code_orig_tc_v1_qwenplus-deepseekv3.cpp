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
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 total = N * N;
    i64 attacked = 0;

    // Calculate rows and columns
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    
    // Calculate diagonals (a + b)
    for (auto d : diag1) {
        i64 x_min = max(1LL, d - N);
        i64 x_max = min(N, d - 1);
        if (x_max >= x_min) {
            attacked += x_max - x_min + 1;
        }
    }

    // Calculate anti-diagonals (a - b)
    for (auto d : diag2) {
        i64 x_min = max(1LL, 1 + d);
        i64 x_max = min(N, N + d);
        if (x_max >= x_min) {
            attacked += x_max - x_min + 1;
        }
    }

    // Subtract overlaps between rows and columns
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                row_col_intersect++;
            }
        }
    }
    attacked -= row_col_intersect;

    // Subtract overlaps between rows and diagonals
    i64 row_diag1_intersect = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (1 <= c && c <= N) {
                if (cols.count(c) && diag2.count(r - c)) {
                    row_diag1_intersect++;
                }
            }
        }
    }
    attacked -= row_diag1_intersect;

    // Subtract overlaps between columns and diagonals
    i64 col_diag2_intersect = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = c + d;
            if (1 <= r && r <= N) {
                if (rows.count(r) && diag1.count(r + c)) {
                    col_diag2_intersect++;
                }
            }
        }
    }
    attacked -= col_diag2_intersect;

    // Add back triple intersections (row, column, and both diagonals)
    i64 triple_intersect = 0;
    for (auto p : pieces) {
        i64 r = p.first;
        i64 c = p.second;
        if (rows.count(r) && cols.count(c) && diag1.count(r + c) && diag2.count(r - c)) {
            triple_intersect++;
        }
    }
    attacked += triple_intersect;

    // The answer is total squares minus attacked squares plus pieces (since they were excluded)
    i64 answer = total - attacked + M;
    cout << answer << "\n";

    return 0;
}