#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    
    // Using set to store positions of occupied cells for faster lookup
    set<pair<long long, long long>> occupied;
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }
    
    // Directions for capturing pieces
    vector<vector<long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    
    // Counting available cells
    long long count = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            bool valid = true;
            for(auto &dir : directions) {
                long long x = i + dir[0], y = j + dir[1];
                if(x >= 1 && x <= n && y >= 1 && y <= n && occupied.find({x, y}) != occupied.end()) {
                    valid = false;
                    break;
                }
            }
            if(valid) count++;
        }
    }
    
    cout << count << endl;
    return 0;
}