#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Step 1: Calculate the number of squares that can be captured by each piece
    vector<i64> capture_rows(N, 0), capture_cols(N, 0), capture_diag1(2 * N - 1, 0), capture_diag2(2 * N - 1, 0);

    for (const auto& p : pieces) {
        i64 r = p.first - 1, c = p.second - 1;
        capture_rows[r]++;
        capture_cols[c]++;
        capture_diag1[r + c]++;
        capture_diag2[r - c + N - 1]++;
    }

    // Step 2: Calculate the number of free squares
    i64 free_squares = N * N;

    // Subtract squares captured by any row
    for (i64 count : capture_rows) {
        free_squares -= count;
    }

    // Subtract squares captured by any column
    for (i64 count : capture_cols) {
        free_squares -= count;
    }

    // Subtract squares captured by any diagonal
    for (i64 count : capture_diag1) {
        free_squares -= count;
    }
    for (i64 count : capture_diag2) {
        free_squares -= count;
    }

    cout << free_squares << "\n";
    return 0;
}