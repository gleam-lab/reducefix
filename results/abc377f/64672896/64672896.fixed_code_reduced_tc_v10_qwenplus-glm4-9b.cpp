#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

using i64 = long long;

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    unordered_set<i64> captured_rows, captured_cols, captured_diag1, captured_diag2;

    // Process each piece to determine captures
    for (const auto& [x, y] : pieces) {
        // Rows and columns
        captured_rows.insert(x);
        captured_cols.insert(y);
        // Diagonals
        captured_diag1.insert(x + y);
        captured_diag2.insert(x - y);
    }

    // Total squares
    i64 total_squares = N * N;

    // Subtract captured squares
    total_squares -= captured_rows.size();
    total_squares -= captured_cols.size();
    total_squares -= captured_diag1.size();
    total_squares -= captured_diag2.size();

    // We should also consider the case where a square is captured by two unique captures
    // This happens when the captures intersect in such a way that a square is counted twice
    // However, since we use sets, this should not happen.

    cout << total_squares << endl;

    return 0;
}