#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

bool isValidMove(int x, int y, vector<vector<bool>>& board) {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size();
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Initialize the board
    vector<vector<bool>> board(n, vector<bool>(n, false));
    
    // Place pieces on the board
    set<pair<int, int>> pieces;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-indexed
        pieces.insert({a, b});
        board[a][b] = true;
        
        // Check all possible captures
        vector<pair<int, int>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for (auto& dir : directions) {
            int nx = a + dir.first;
            int ny = b + dir.second;
            if (isValidMove(nx, ny, board)) {
                pieces.erase({nx, ny});
            }
        }
    }
    
    // Calculate the number of available cells
    long long availableCells = n * n - pieces.size();
    cout << availableCells % MOD << endl;
    
    return 0;
}