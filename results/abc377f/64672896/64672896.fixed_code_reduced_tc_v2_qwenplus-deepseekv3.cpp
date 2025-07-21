#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64, 2>> g(M);
    set<i64> rows, cols, diag1, diag2;
    set<array<i64, 2>> pieces;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        pieces.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    i64 res = N * N;
    // Subtract rows
    res -= N * rows.size();
    // Subtract columns
    res -= N * cols.size();
    // Subtract diagonals (a + b)
    for (auto d : diag1) {
        i64 cnt = 0;
        i64 start = max(1LL, d - N);
        i64 end = min(N, d - 1);
        if (start <= end) {
            cnt = end - start + 1;
        }
        res -= cnt;
    }
    // Subtract anti-diagonals (a - b)
    for (auto d : diag2) {
        i64 cnt = 0;
        i64 start = max(1LL, 1 - d);
        i64 end = min(N, N - d);
        if (start <= end) {
            cnt = end - start + 1;
        }
        res -= cnt;
    }
    // Add back intersections: rows and columns
    i64 row_col = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) {
                continue;
            }
            row_col++;
        }
    }
    res += row_col;
    // Add back intersections: rows and diag1
    i64 row_diag1 = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (c >= 1 && c <= N && !pieces.count({r, c})) {
                row_diag1++;
            }
        }
    }
    res += row_diag1;
    // Add back intersections: rows and diag2
    i64 row_diag2 = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N && !pieces.count({r, c})) {
                row_diag2++;
            }
        }
    }
    res += row_diag2;
    // Add back intersections: columns and diag1
    i64 col_diag1 = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (r >= 1 && r <= N && !pieces.count({r, c})) {
                col_diag1++;
            }
        }
    }
    res += col_diag1;
    // Add back intersections: columns and diag2
    i64 col_diag2 = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (r >= 1 && r <= N && !pieces.count({r, c})) {
                col_diag2++;
            }
        }
    }
    res += col_diag2;
    // Add back intersections: diag1 and diag2
    i64 diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            i64 r = (d1 + d2) / 2;
            i64 c = (d1 - d2) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N && !pieces.count({r, c})) {
                diag1_diag2++;
            }
        }
    }
    res += diag1_diag2;
    // Subtract intersections: rows, columns, and diag1
    i64 row_col_diag1 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (!pieces.count({r, c})) {
                i64 d = r + c;
                if (diag1.count(d)) {
                    row_col_diag1++;
                }
            }
        }
    }
    res -= row_col_diag1;
    // Subtract intersections: rows, columns, and diag2
    i64 row_col_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (!pieces.count({r, c})) {
                i64 d = r - c;
                if (diag2.count(d)) {
                    row_col_diag2++;
                }
            }
        }
    }
    res -= row_col_diag2;
    // Subtract intersections: rows, diag1, and diag2
    i64 row_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            i64 c = d1 - r;
            if (c >= 1 && c <= N && !pieces.count({r, c})) {
                i64 d2 = r - c;
                if (diag2.count(d2)) {
                    row_diag1_diag2++;
                }
            }
        }
    }
    res -= row_diag1_diag2;
    // Subtract intersections: columns, diag1, and diag2
    i64 col_diag1_diag2 = 0;
    for (auto c : cols) {
        for (auto d1 : diag1) {
            i64 r = d1 - c;
            if (r >= 1 && r <= N && !pieces.count({r, c})) {
                i64 d2 = r - c;
                if (diag2.count(d2)) {
                    col_diag1_diag2++;
                }
            }
        }
    }
    res -= col_diag1_diag2;
    // Add back intersections: rows, columns, diag1, and diag2
    i64 row_col_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (!pieces.count({r, c})) {
                i64 d1 = r + c;
                i64 d2 = r - c;
                if (diag1.count(d1) && diag2.count(d2)) {
                    row_col_diag1_diag2++;
                }
            }
        }
    }
    res += row_col_diag1_diag2;
    cout << res << "\n";
    return 0;
}