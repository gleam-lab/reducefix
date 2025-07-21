#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Using a set to store positions of existing pieces to allow O(1) lookups
    set<pair<long long, long long>> ex;
    
    // Directions for capturing moves
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    // Populate the set with existing pieces
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        ex.insert({a, b});
    }

    // Initialize count of valid cells
    long long ans = 0;

    // Iterate over all possible cells
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            bool valid = true;
            
            // Check all possible capture directions
            for (int k = 0; k < 8; ++k) {
                long long x = i + dx[k], y = j + dy[k];
                if (x > 0 && x <= n && y > 0 && y <= n && ex.find({x, y}) != ex.end()) {
                    valid = false;
                    break;
                }
            }

            // If the cell is valid, increment the count
            if (valid) {
                ++ans;
            }
        }
    }

    // Output the number of valid cells
    cout << ans << endl;
}