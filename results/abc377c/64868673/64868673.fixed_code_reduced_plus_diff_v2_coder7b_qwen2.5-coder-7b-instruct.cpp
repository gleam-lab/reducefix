#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    unordered_set<long long> capturable;
    
    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));
    
    // Directions a piece can move to capture another piece
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    // Read the positions of existing pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        grid[a][b] = true;
        
        // Mark all capturable squares from this piece's position
        for (auto& dir : directions) {
            long long x = a + dir.first;
            long long y = b + dir.second;
            while (x >= 1 && x <= n && y >= 1 && y <= n) {
                capturable.insert(1LL * x * n + y);
                x += dir.first;
                y += dir.second;
            }
        }
    }
    
    // Count the number of valid empty squares
    long long validSquares = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            if (!grid[i][j] && !capturable.count(1LL * i * n + j)) {
                ++validSquares;
            }
        }
    }
    
    cout << validSquares << endl;
    
    return 0;
}