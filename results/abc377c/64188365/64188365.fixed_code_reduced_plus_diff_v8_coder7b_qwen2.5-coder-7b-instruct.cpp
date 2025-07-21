#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000000 + 1;
bitset<MAX_N> board;

bool isValid(int n, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    // Initialize the board
    board.reset();

    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        pieces[i].first--; // Adjust to zero-based index
        pieces[i].second--;
    }

    // Mark capturable positions
    for (const auto& [x, y] : pieces) {
        for (int dx = -2; dx <= 2; dx += 2) {
            for (int dy = -2; dy <= 2; dy += 2) {
                int nx = x + dx, ny = y + dy;
                if (isValid(n, nx, ny)) {
                    board[nx * n + ny] = true;
                }
            }
        }
    }

    // Count empty squares
    long long emptySquares = 0;
    for (long long i = 0; i < n * n; ++i) {
        if (!board[i]) {
            emptySquares++;
        }
    }

    cout << emptySquares << endl;

    return 0;
}