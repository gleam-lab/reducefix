#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Using set to store positions of occupied squares for faster lookup
    set<pair<long long, long long>> ex;
    long long ans = n * n; // Initially assume all squares are empty
    
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Check if the current position is already occupied
        if (!ex.count({a, b})) {
            ex.insert({a, b});
            
            // Check all possible moves from the current position
            for (int k = 0; k < 8; ++k) {
                long long x = a + dx[k], y = b + dy[k];
                
                // Ensure the move stays within bounds
                if (x > 0 && x <= n && y > 0 && y <= n) {
                    // If the move lands on an unoccupied square, subtract it from the count
                    if (!ex.count({x, y})) {
                        --ans;
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}