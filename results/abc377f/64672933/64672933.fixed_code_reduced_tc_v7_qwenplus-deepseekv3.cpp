#include<bits/stdc++.h>
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

    i64 forbidden = 0;
    // Rows
    forbidden += rows.size() * N;
    // Columns
    forbidden += cols.size() * N;
    // Diagonals a + b
    for (auto s : diag1) {
        i64 x_min = max(1LL, s - N);
        i64 x_max = min(N, s - 1);
        if (x_min > x_max) continue;
        forbidden += x_max - x_min + 1;
    }
    // Diagonals a - b
    for (auto d : diag2) {
        i64 x_min = max(1LL, 1 + d);
        i64 x_max = min(N, N + d);
        if (x_min > x_max) continue;
        forbidden += x_max - x_min + 1;
    }

    // Overlaps between rows and columns
    i64 row_col_intersect = 0;
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.count(a + b) && diag2.count(a - b)) {
                row_col_intersect++;
            }
        }
    }
    forbidden -= row_col_intersect;

    // Overlaps between rows and diagonals (i+j)
    i64 row_diag1_intersect = 0;
    for (auto a : rows) {
        for (auto s : diag1) {
            i64 b = s - a;
            if (b >= 1 && b <= N && cols.count(b) && diag2.count(a - b)) {
                row_diag1_intersect++;
            }
        }
    }
    forbidden -= row_diag1_intersect;

    // Overlaps between columns and diagonals (i-j)
    i64 col_diag2_intersect = 0;
    for (auto b : cols) {
        for (auto d : diag2) {
            i64 a = b + d;
            if (a >= 1 && a <= N && rows.count(a) && diag1.count(a + b)) {
                col_diag2_intersect++;
            }
        }
    }
    forbidden -= col_diag2_intersect;

    // Overlaps between diagonals (i+j) and diagonals (i-j)
    i64 diag1_diag2_intersect = 0;
    for (auto s : diag1) {
        for (auto d : diag2) {
            if ((s + d) % 2 != 0) continue;
            i64 a = (s + d) / 2;
            i64 b = (s - d) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N && rows.count(a) && cols.count(b)) {
                diag1_diag2_intersect++;
            }
        }
    }
    forbidden -= diag1_diag2_intersect;

    // Overlaps between all four conditions (row, column, diag1, diag2)
    i64 all_intersect = 0;
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b) && diag1.count(a + b) && diag2.count(a - b)) {
            all_intersect++;
        }
    }
    forbidden += all_intersect;

    i64 total = N * N - forbidden;
    cout << total << "\n";

    return 0;
}