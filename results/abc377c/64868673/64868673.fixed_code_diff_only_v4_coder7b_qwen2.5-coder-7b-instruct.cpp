#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store the positions of existing pieces
    set<pair<long long, long long>> pieces;
    
    // Directions in which a piece can capture another piece
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, 
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    // Read the positions of existing pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }
    
    // Function to check if a position is within bounds
    auto isValid = [&](long long x, long long y) {
        return x >= 1 && x <= n && y >= 1 && y <= n;
    };
    
    // Count the number of invalid positions that can be captured
    long long invalidCount = 0;
    for (auto& [x, y] : pieces) {
        for (auto& [dx, dy] : directions) {
            long long nx = x + dx, ny = y + dy;
            if (isValid(nx, ny)) {
                invalidCount++;
            }
        }
    }
    
    // Total number of valid empty squares
    long long validSquares = n * n - invalidCount;
    
    cout << validSquares << endl;
    
    return 0;
}