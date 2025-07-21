#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // Set to keep track of positions that cannot be used
    set<pair<long long, long long>> invalid_positions;
    
    // Directions for capturing pieces
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Mark the position of the current piece
        invalid_positions.insert({a, b});
        
        // Mark all positions that the current piece can capture
        for (int j = 0; j < 8; ++j) {
            long long x = a + dx[j];
            long long y = b + dy[j];
            
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                invalid_positions.insert({x, y});
            }
        }
    }
    
    // Total number of valid positions
    long long total_valid_positions = n * n - invalid_positions.size();
    
    cout << total_valid_positions << endl;
    
    return 0;
}