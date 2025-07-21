#include <iostream>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    long long capture_rows[2 * N + 1] = {0}; // Half size for 0-based index
    long long capture_cols[2 * N + 1] = {0};
    long long capture_diag1[2 * N + 1] = {0};
    long long capture_diag2[2 * N + 1] = {0};

    // Read pieces and calculate captures
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y; // Convert to 0-based index
        pieces[i] = {x, y};
        capture_rows[x + N] += 1; // x + N for 0-based index
        capture_cols[y + N] += 1;
        capture_diag1[x - y + N] += 1;
        capture_diag2[x + y + N] += 1;
    }

    // Calculate number of captured squares
    long long captured_squares = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int row_captures = capture_rows[i + N];
            int col_captures = capture_cols[j + N];
            int diag1_captures = capture_diag1[i - j + N];
            int diag2_captures = capture_diag2[i + j + N];

            // A square is captured if it is captured by any row, column, or diagonal
            if (row_captures + col_captures + diag1_captures + diag2_captures > 0) {
                captured_squares += 1;
            }
        }
    }

    // Total number of squares minus captured squares
    long long total_squares = N * N;
    long long result = total_squares - captured_squares;
    cout << result << '\n';

    return 0;
}