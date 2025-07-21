#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Sets to check if a row, column, or diagonal is fully covered
    vector<bool> rows(N + 1, false), cols(N + 1, false);
    vector<vector<bool>> diag1(N + 1, vector<bool>(N + 1, false)), diag2(N + 1, vector<bool>(N + 1, false));

    // Mark the rows, columns, and diagonals covered by pieces
    for (auto& p : pieces) {
        rows[p.first] = true;
        cols[p.second] = true;
        diag1[p.first][p.second] = true;
        diag2[p.first][p.second] = true;
    }

    long long count = N * N; // Total number of squares

    // Subtract the number of squares covered by rows
    for (auto& row : rows) {
        if (row) count -= N;
    }

    // Subtract the number of squares covered by columns
    for (auto& col : cols) {
        if (col) count -= N;
    }

    // Subtract the number of squares covered by both diagonals
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (diag1[i][j] && diag2[i][j]) {
                count -= 1;
            }
        }
    }

    cout << count << endl;
    return 0;
}