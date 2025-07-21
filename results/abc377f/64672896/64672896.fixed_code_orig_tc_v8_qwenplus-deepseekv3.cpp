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

    // Rows
    for (auto r : rows) {
        attacked += N;
    }

    // Columns
    for (auto c : cols) {
        attacked += N;
    }

    // Diagonals (i + j)
    for (auto d : diag1) {
        i64 L = max(1LL, d - N);
        i64 R = min(N, d - 1);
        if (L <= R) {
            attacked += (R - L + 1);
        }
    }

    // Diagonals (i - j)
    for (auto d : diag2) {
        i64 L = max(1LL, 1 + d);
        i64 R = min(N, N + d);
        if (L <= R) {
            attacked += (R - L + 1);
        }
    }

    // Subtract intersections of rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections of rows and diag1
    for (auto r : rows) {
        for (auto d1 : diag1) {
            i64 c = d1 - r;
            if (c >= 1 && c <= N && cols.count(c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections of rows and diag2
    for (auto r : rows) {
        for (auto d2 : diag2) {
            i64 c = r - d2;
            if (c >= 1 && c <= N && cols.count(c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections of columns and diag1
    for (auto c : cols) {
        for (auto d1 : diag1) {
            i64 r = d1 - c;
            if (r >= 1 && r <= N && rows.count(r)) {
                attacked -= 1;
            }
        }
    }

    // Subtract intersections of columns and diag2
    for (auto c : cols) {
        for (auto d2 : diag2) {
            i64 r = c + d2;
            if (r >= 1 && r <= N && rows.count(r)) {
                attacked -= 1;
            }
        }
    }

    // Add back intersections of rows, columns, diag1, diag2 (inclusion-exclusion)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                attacked += 1;
            }
        }
    }

    // Total safe squares
    i64 total_squares = N * N;
    i64 safe_squares = total_squares - attacked + occupied.size();
    for (auto p : occupied) {
        i64 r = p.first;
        i64 c = p.second;
        if (rows.count(r) || cols.count(c) || diag1.count(r + c) || diag2.count(r - c)) {
            safe_squares -= 1;
        }
    }

    cout << safe_squares << "\n";

    return 0;
}