#include <bits/stdc++.h>
using namespace std;

bool isValidMove(const int& n, const int& x, const int& y, vector<vector<bool>>& board) {
    return x >= 0 && x < n && y >= 0 && y < n && !board[x][y];
}

int countValidPositions(const int& n, const int& m, vector<pair<int, int>>& positions) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    
    // Mark positions that already have a piece
    for (const auto& pos : positions) {
        board[pos.first - 1][pos.second - 1] = true;
    }

    int validCount = 0;
    // Define all possible moves
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    
    // Check each cell to see if placing a new piece there is valid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool canPlace = true;
            for (const auto& move : moves) {
                int newX = i + move.first;
                int newY = j + move.second;
                if (isValidMove(n, newX, newY, board)) {
                    canPlace = false;
                    break;
                }
            }
            if (canPlace) {
                ++validCount;
            }
        }
    }
    
    return validCount;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<int, int>> positions(m);
    for (auto& pos : positions) {
        cin >> pos.first >> pos.second;
    }
    cout << countValidPositions(n, m, positions) << endl;
    return 0;
}