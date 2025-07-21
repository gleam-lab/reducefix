#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    set<pair<int, int>> pieces;

    // Mark the positions of the pieces
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        board[a][b] = true;
        pieces.insert({a, b});
    }

    // Directions for capturing pieces
    vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    // Function to check if placing a piece at (x, y) is valid
    auto isValidPlacement = [&](int x, int y) {
        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !board[nx][ny]) {
                if (pieces.find({nx, ny}) != pieces.end()) return false;
            }
        }
        return true;
    };

    // Count the number of valid placements
    int validCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!board[i][j] && isValidPlacement(i, j)) {
                ++validCount;
            }
        }
    }

    cout << validCount << endl;
    return 0;
}