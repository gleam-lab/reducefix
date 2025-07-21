#include <bits/stdc++.h>
using namespace std;

// Function to check if placing a piece at (x, y) is valid
bool isValid(int x, int y, const vector<vector<bool>>& board) {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<bool>> board(n, vector<bool>(n, false));

    // Mark all positions where pieces can capture other pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Adjusting indices to zero-based
        board[a][b] = true;
        for (const auto& [dx, dy] : {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}}) {
            long long nx = a + dx, ny = b + dy;
            if (isValid(nx, ny, board)) {
                board[nx][ny] = true;
            }
        }
    }

    // Count the number of empty positions
    long long count = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (!board[i][j]) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}