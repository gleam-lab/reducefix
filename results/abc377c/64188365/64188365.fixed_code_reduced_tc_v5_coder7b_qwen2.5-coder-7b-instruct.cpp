#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    
    // Set to keep track of occupied positions and potential capturing positions
    set<pair<long long, long long>> occupied, capturing;
    
    rep(i, m) {
        cin >> a >> b;
        a--; b--; // Convert to zero-based index
        
        occupied.emplace(a, b);
        
        // Check all possible capturing positions
        vector<pair<int, int>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for (auto [dx, dy] : directions) {
            long long x = a + dx, y = b + dy;
            if (x >= 0 && x < n && y >= 0 && y < n) {
                capturing.emplace(x, y);
            }
        }
    }
    
    // The number of valid positions is total positions minus occupied positions
    cout << n * n - occupied.size() << endl;
}