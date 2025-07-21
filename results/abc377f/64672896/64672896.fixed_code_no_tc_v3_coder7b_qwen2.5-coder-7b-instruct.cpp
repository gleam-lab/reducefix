#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N, M;
    cin >> N >> M;

    set<pair<int64_t, int64_t>> captured_squares;

    for (int64_t i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;

        // Capture in the same row
        for (int64_t j = 1; j <= N; ++j) {
            if (j != b) {
                captured_squares.insert({a, j});
            }
        }

        // Capture in the same column
        for (int64_t j = 1; j <= N; ++j) {
            if (j != a) {
                captured_squares.insert({j, b});
            }
        }

        // Capture in the same diagonal
        int64_t diag_sum = a + b;
        for (int64_t j = 1; j <= N; ++j) {
            if (j != b && j + (diag_sum - j) != a) {
                captured_squares.insert({j, diag_sum - j});
            }
        }

        // Capture in the same antidiagonal
        int64_t anti_diag_diff = a - b;
        for (int64_t j = 1; j <= N; ++j) {
            if (j != b && j - (anti_diag_diff - j) != a) {
                captured_squares.insert({j, j - anti_diag_diff});
            }
        }
    }

    int64_t total_squares = N * N;
    int64_t valid_squares = total_squares - captured_squares.size();

    cout << valid_squares << "\n";

    return 0;
}