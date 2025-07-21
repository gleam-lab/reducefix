#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store all positions of existing pieces
    set<pair<long long, long long>> pieces;
    
    // Directions for capturing squares
    vector<pair<int, int>> directions = {
        {2, 1}, {2, -1}, {1, 2}, {1, -2},
        {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}
    };
    
    // Mark all unsafe squares
    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        --x; --y; // Convert 1-based to 0-based index
        
        pieces.insert({x, y});
        
        for (auto& dir : directions) {
            long long nx = x + dir.first;
            long long ny = y + dir.second;
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                pieces.insert({nx, ny});
            }
        }
    }
    
    // Count empty squares
    long long empty_squares = n * n - pieces.size();
    
    cout << empty_squares << endl;
    
    return 0;
}