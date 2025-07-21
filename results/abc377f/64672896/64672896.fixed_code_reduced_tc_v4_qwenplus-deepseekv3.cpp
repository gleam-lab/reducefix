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
    set<array<i64, 2>> occupied;
    
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }
    
    i64 row_cnt = rows.size();
    i64 col_cnt = cols.size();
    i64 diag1_cnt = diag1.size();
    i64 diag2_cnt = diag2.size();
    
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c})) continue;
            if (diag1.count(r + c) || diag2.count(r - c)) {
                row_col_intersect++;
            }
        }
    }
    
    i64 row_diag1_intersect = 0;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            i64 c = d1 - r;
            if (c < 1 || c > N) continue;
            if (occupied.count({r, c})) continue;
            if (cols.count(c) || diag2.count(r - c)) {
                row_diag1_intersect++;
            }
        }
    }
    
    i64 row_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto d2 : diag2) {
            i64 c = r - d2;
            if (c < 1 || c > N) continue;
            if (occupied.count({r, c})) continue;
            if (cols.count(c) || diag1.count(r + c)) {
                row_diag2_intersect++;
            }
        }
    }
    
    i64 col_diag1_intersect = 0;
    for (auto c : cols) {
        for (auto d1 : diag1) {
            i64 r = d1 - c;
            if (r < 1 || r > N) continue;
            if (occupied.count({r, c})) continue;
            if (rows.count(r) || diag2.count(r - c)) {
                col_diag1_intersect++;
            }
        }
    }
    
    i64 col_diag2_intersect = 0;
    for (auto c : cols) {
        for (auto d2 : diag2) {
            i64 r = d2 + c;
            if (r < 1 || r > N) continue;
            if (occupied.count({r, c})) continue;
            if (rows.count(r) || diag1.count(r + c)) {
                col_diag2_intersect++;
            }
        }
    }
    
    i64 diag1_diag2_intersect = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            i64 r = (d1 + d2) / 2;
            i64 c = (d1 - d2) / 2;
            if (r < 1 || r > N || c < 1 || c > N) continue;
            if (occupied.count({r, c})) continue;
            if (rows.count(r) || cols.count(c)) {
                diag1_diag2_intersect++;
            }
        }
    }
    
    i64 total_attacked = row_cnt * N + col_cnt * N - row_cnt * col_cnt;
    total_attacked += diag1_cnt * (2 * N - 1) - diag1_cnt * (row_cnt + col_cnt) + row_col_intersect;
    total_attacked += diag2_cnt * (2 * N - 1) - diag2_cnt * (row_cnt + col_cnt) + row_col_intersect;
    total_attacked -= (row_diag1_intersect + row_diag2_intersect + col_diag1_intersect + col_diag2_intersect);
    total_attacked += diag1_diag2_intersect;
    
    i64 safe_squares = N * N - total_attacked - M;
    cout << safe_squares << "\n";
    
    return 0;
}