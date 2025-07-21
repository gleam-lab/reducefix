#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;
    
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        
        // Convert coordinates to a unique hash value to store in set
        long long pos = ((a - 1) * n + b);
        
        // Check all possible moves from this position
        vector<pair<long long, long long>> moves = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for (auto &move : moves) {
            long long x = a + move.first;
            long long y = b + move.second;
            
            // Convert new coordinates to a unique hash value
            long long newPos = ((x - 1) * n + y);
            
            // If the new position is within bounds and not already occupied
            if (x > 0 && x <= n && y > 0 && y <= n && !ex.count(newPos)) {
                --ans;
                ex.insert(newPos); // Mark this position as captured
            }
        }
        
        // Mark the current position as occupied
        ex.insert(pos);
    }

    cout << ans << endl;
}