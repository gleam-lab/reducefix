#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    
    // Set to store positions of all pieces including those that would be captured
    set<pair<long long, long long>> c;
    
    // Set to store positions of pieces that can be placed without being captured
    set<pair<long long, long long>> safe_positions;
    
    rep(i, m) {
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        
        // Add current piece position to both sets
        c.emplace(a, b);
        
        // Check all possible capture positions
        vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (auto &dir : directions) {
            int x = a + dir.first, y = b + dir.second;
            if (x >= 0 && x < n && y >= 0 && y < n) {
                c.emplace(x, y);
            }
        }
    }

    // All empty positions initially
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            safe_positions.emplace(i, j);
        }
    }

    // Remove positions that will be captured
    for (auto pos : c) {
        safe_positions.erase(pos);
    }

    cout << safe_positions.size() << endl;
    return 0;
}