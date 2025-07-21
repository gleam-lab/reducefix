#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Set to store positions that cannot be captured
    set<pair<long long, long long>> uncapturable;
    
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index
        
        // Check all possible positions that can capture (a, b)
        vector<pair<int, int>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        
        for (auto [dx, dy] : directions) {
            long long x = a + dx, y = b + dy;
            if (x >= 0 && x < n && y >= 0 && y < n) {
                uncapturable.insert({x, y});
            }
        }
    }
    
    // Total number of squares minus the number of uncapturable squares
    cout << n * n - uncapturable.size() << endl;
}