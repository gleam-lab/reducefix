#include <iostream>
#include <vector>

using namespace std;

string grid[1001]; // Assuming a maximum board size of 1001x1001

bool isSafe(int r, int c) {
    int directions[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    for (auto& dir : directions) {
        int nr = r + dir[0], nc = c + dir[1];
        if (nr < 1 || nr > 1000 || nc < 1 || nc > 1000) continue; // Check boundaries
        if (grid[nr][nc] == 'X') return false; // Check if the piece exists
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        grid[i] = string(1001, '.'); // Initialize the board with empty squares
    }
    
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        grid[r][c] = 'X'; // Place pieces on the board
    }
    
    int safeSquares = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '.' && isSafe(i, j)) {
                safeSquares++; // Count safe squares
            }
        }
    }
    
    cout << safeSquares << endl;
    return 0;
}