#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> row_captured(N + 1, 0);
    vector<long long> col_captured(N + 1, 0);
    vector<long long> diag_captured(2 * N, 0);
    vector<long long> antidiag_captured(2 * N, 0);

    for (int i = 0; i < M; ++i) {
        long long x, y;
        cin >> x >> y;
        --x; --y; // Adjust indices to zero-based

        row_captured[x]++;
        col_captured[y]++;
        diag_captured[x + y]++;
        antidiag_captured[x - y + N]++;
    }

    long long total_empty_squares = N * N;

    for (int i = 0; i < N; ++i) {
        total_empty_squares -= row_captured[i];
        total_empty_squares -= col_captured[i];
        total_empty_squares -= diag_captured[i];
        total_empty_squares -= antidiag_captured[i];
    }

    // Apply inclusion-exclusion principle
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (row_captured[i] > 0 && col_captured[j] > 0) {
                total_empty_squares += 1;
            }
            if (diag_captured[i + j] > 0 && col_captured[j] > 0) {
                total_empty_squares += 1;
            }
            if (antidiag_captured[i - j + N] > 0 && col_captured[j] > 0) {
                total_empty_squares += 1;
            }
            if (diag_captured[i + j] > 0 && antidiag_captured[i - j + N] > 0) {
                total_empty_squares += 1;
            }
            if (diag_captured[i + j] > 0 && col_captured[j] > 0 && antidiag_captured[i - j + N] > 0) {
                total_empty_squares -= 1;
            }
            if (diag_captured[i + j] > 0 && col_captured[j] > 0 && row_captured[i] > 0) {
                total_empty_squares -= 1;
            }
            if (col_captured[j] > 0 && antidiag_captured[i - j + N] > 0 && row_captured[i] > 0) {
                total_empty_squares -= 1;
            }
            if (diag_captured[i + j] > 0 && antidiag_captured[i - j + N] > 0 && row_captured[i] > 0) {
                total_empty_squares += 1;
            }
        }
    }

    cout << total_empty_squares << endl;

    return 0;
}