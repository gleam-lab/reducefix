#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    
    set<pair<long long, long long>> occupied;
    for(long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        --x, --y; // Adjusting for zero-based indexing
        occupied.insert({x, y});
        
        // Check all possible moves from this position
        vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for(auto &dir : directions) {
            long long nx = x + dir.first, ny = y + dir.second;
            if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                occupied.insert({nx, ny});
            }
        }
    }

    cout << n * n - occupied.size() << '\n';
    return 0;
}