#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

    i64 row_count = rows.size();
    i64 col_count = cols.size();
    i64 diag1_count = diag1.size();
    i64 diag2_count = diag2.size();

    i64 unsafe = 0;

    // Rows and columns
    unsafe += row_count * N;
    unsafe += col_count * N;
    unsafe -= row_count * col_count; // Overlap of row and column

    // Diagonals (a + b)
    unsafe += diag1_count * N;
    // Subtract overlaps between diag1 and rows/columns
    for (i64 s : diag1) {
        i64 min_x = max(1LL, s - N);
        i64 max_x = min(N, s - 1);
        if (min_x > max_x) continue;
        unsafe -= upper_bound(rows.begin(), rows.end(), max_x) - lower_bound(rows.begin(), rows.end(), min_x);
    }
    // Subtract overlaps between diag1 and cols
    for (i64 s : diag1) {
        i64 min_y = max(1LL, s - N);
        i64 max_y = min(N, s - 1);
        if (min_y > max_y) continue;
        unsafe -= upper_bound(cols.begin(), cols.end(), max_y) - lower_bound(cols.begin(), cols.end(), min_y);
    }
    // Add back overlaps between diag1 and both rows and cols (intersection of row, column, and diag1)
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b) && diag1.count(a + b)) {
            unsafe += 1;
        }
    }

    // Diagonals (a - b)
    unsafe += diag2_count * N;
    // Subtract overlaps between diag2 and rows/columns
    for (i64 d : diag2) {
        i64 min_x = max(1LL, 1 + d);
        i64 max_x = min(N, N + d);
        if (min_x > max_x) continue;
        unsafe -= upper_bound(rows.begin(), rows.end(), max_x) - lower_bound(rows.begin(), rows.end(), min_x);
    }
    for (i64 d : diag2) {
        i64 min_y = max(1LL, 1 - d);
        i64 max_y = min(N, N - d);
        if (min_y > max_y) continue;
        unsafe -= upper_bound(cols.begin(), cols.end(), max_y) - lower_bound(cols.begin(), cols.end(), min_y);
    }
    // Add back overlaps between diag2 and both rows and cols (intersection of row, column, and diag2)
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b) && diag2.count(a - b)) {
            unsafe += 1;
        }
    }

    // Subtract overlaps between diag1 and diag2
    set<pair<i64, i64>> piece_set(pieces.begin(), pieces.end());
    for (i64 s : diag1) {
        for (i64 d : diag2) {
            if ((s + d) % 2 != 0) continue;
            i64 x = (s + d) / 2;
            i64 y = (s - d) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (piece_set.count({x, y})) {
                    unsafe -= 1;
                }
            }
        }
    }

    // Total safe squares
    i64 total = N * N;
    i64 safe = total - unsafe;
    cout << safe << "\n";

    return 0;
}