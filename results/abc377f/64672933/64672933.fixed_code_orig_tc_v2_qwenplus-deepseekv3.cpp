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
        occupied.insert({a, b});
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 unsafe = 0;

    // Count rows
    unsafe += rows.size() * N;
    // Count columns
    unsafe += cols.size() * N;
    // Count diagonals (i + j = k)
    for (i64 k : diag1) {
        i64 start_i = max(1LL, k - N);
        i64 end_i = min(N, k - 1);
        if (start_i > end_i) continue;
        unsafe += (end_i - start_i + 1);
    }
    // Count anti-diagonals (i - j = k)
    for (i64 k : diag2) {
        i64 start_i = max(1LL, 1 + k);
        i64 end_i = min(N, N + k);
        if (start_i > end_i) continue;
        unsafe += (end_i - start_i + 1);
    }

    // Subtract intersections: row and column
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (occupied.count({r, c})) continue;
            if (diag1.count(r + c) || diag2.count(r - c)) {
                unsafe -= 1;
            }
        }
    }

    // Subtract intersections: row and diag1
    for (i64 r : rows) {
        for (i64 k : diag1) {
            i64 c = k - r;
            if (c >= 1 && c <= N && !occupied.count({r, c}) && cols.count(c)) {
                unsafe -= 1;
            }
        }
    }

    // Subtract intersections: row and diag2
    for (i64 r : rows) {
        for (i64 k : diag2) {
            i64 c = r - k;
            if (c >= 1 && c <= N && !occupied.count({r, c}) && cols.count(c)) {
                unsafe -= 1;
            }
        }
    }

    // Subtract intersections: column and diag1
    for (i64 c : cols) {
        for (i64 k : diag1) {
            i64 r = k - c;
            if (r >= 1 && r <= N && !occupied.count({r, c}) && rows.count(r)) {
                unsafe -= 1;
            }
        }
    }

    // Subtract intersections: column and diag2
    for (i64 c : cols) {
        for (i64 k : diag2) {
            i64 r = k + c;
            if (r >= 1 && r <= N && !occupied.count({r, c}) && rows.count(r)) {
                unsafe -= 1;
            }
        }
    }

    // Subtract intersections: diag1 and diag2
    for (i64 k1 : diag1) {
        for (i64 k2 : diag2) {
            i64 r = (k1 + k2) / 2;
            i64 c = (k1 - k2) / 2;
            if ((k1 + k2) % 2 == 0 && (k1 - k2) % 2 == 0 && r >= 1 && r <= N && c >= 1 && c <= N && !occupied.count({r, c}) && rows.count(r) && cols.count(c)) {
                unsafe -= 1;
            }
        }
    }

    // Add back the occupied squares since they were subtracted multiple times
    unsafe += M;

    i64 total = N * N;
    i64 safe = total - unsafe;

    cout << safe << "\n";

    return 0;
}