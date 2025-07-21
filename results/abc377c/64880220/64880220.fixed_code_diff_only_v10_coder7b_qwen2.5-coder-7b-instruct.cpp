#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;
    
    // Initialize a set to store positions of existing pieces
    unordered_set<long long> ex;
    long long MOD = 1000000007; // To handle large numbers
    
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        
        // Convert the 2D coordinate to a unique 1D value using modulo operation
        long long pos = (a - 1) * n + b;
        ex.insert(pos);
        
        // Check all possible moves from the current position
        vector<pair<long long, long long>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        
        for (auto &move : moves) {
            long long x = a + move.first;
            long long y = b + move.second;
            
            // Check if the new position is within bounds and not already occupied
            if (x > 0 && x <= n && y > 0 && y <= n && !ex.count((x - 1) * n + y)) {
                ex.insert((x - 1) * n + y);
            }
        }
    }

    // Calculate the number of available cells
    long long total_cells = n * n;
    long long available_cells = (total_cells - ex.size()) % MOD;
    
    cout << available_cells << endl;
    
    return 0;
}