#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;

    set<i64> row_set, col_set, diag1_set, diag2_set;
    set<pair<i64, i64>> piece_set;

    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        row_set.insert(a);
        col_set.insert(b);
        diag1_set.insert(a + b);
        diag2_set.insert(a - b);
        piece_set.emplace(a, b);
    }

    i64 total_captured = 0;

    // Count squares captured by rows and columns
    total_captured += row_set.size() * N;
    total_captured += col_set.size() * N;

    // Count squares captured by diagonals
    total_captured += diag1_set.size() * N;
    total_captured += diag2_set.size() * N;

    // Subtract overlaps: intersections of rows and columns with pieces
    for (const auto& [a, b] : piece_set) {
        if (row_set.count(a) && col_set.count(b)) {
            total_captured -= 1; // square (a,b) was counted twice
        }
    }

    // Subtract overlaps: intersections of diagonals with pieces
    for (const auto& [a, b] : piece_set) {
        if (diag1_set.count(a + b)) {
            total_captured -= 1; // square (a,b) was counted in diagonal 1
        }
        if (diag2_set.count(a - b)) {
            total_captured -= 1; // square (a,b) was counted in diagonal 2
        }
    }

    // Subtract overlaps between lines (rows/cols/diagonals)
    for (const auto& r : row_set) {
        for (const auto& c : col_set) {
            i64 cnt = 0;
            if (row_set.count(r)) cnt++;
            if (col_set.count(c)) cnt++;
            if (diag1_set.count(r + c)) cnt++;
            if (diag2_set.count(r - c)) cnt++;
            if (cnt > 1) total_captured -= (cnt - 1); // overcounted
        }
    }

    // Total empty squares = all squares - captured squares
    i64 total_squares = N * N;
    i64 answer = total_squares - total_captured;

    cout << answer << '\n';

    return 0;
}