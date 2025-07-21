#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> rows(N + 1, 0), cols(N + 1, 0);
    vector<i64> diag1(2 * N + 1, 0), diag2(-N - 1, 0);
    
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        rows[a]++; cols[b]++; diag1[2 * (a - 1) + b]++; diag2[2 * a + b - N]++; 
    }

    i64 total_empty = N * N;
    i64 captured_by_row = 0, captured_by_col = 0, captured_by_diag1 = 0, captured_by_diag2 = 0;

    for (i64 i = 1; i <= N; ++i) {
        captured_by_row += rows[i];
        captured_by_col += cols[i];
        captured_by_diag1 += diag1[2 * i - 1];
        captured_by_diag2 += diag2[2 * i - 1];
    }

    // Subtract the number of squares that are captured by row, column, and diagonals
    total_empty -= captured_by_row;
    total_empty -= captured_by_col;
    total_empty -= captured_by_diag1;
    total_empty -= captured_by_diag2;

    // Each square is counted twice in the above subtraction (once for each line it belongs to)
    // So we need to add these squares back to get the correct count
    total_empty += captured_by_row * (N - captured_by_row);
    total_empty += captured_by_col * (N - captured_by_col);
    total_empty += captured_by_diag1 * (N - captured_by_diag1);
    total_empty += captured_by_diag2 * (N - captured_by_diag2);

    cout << total_empty << '\n';
    return 0;
}