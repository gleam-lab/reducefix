#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    set<pair<long long, long long>> occupied;
    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        --x, --y; // Adjusting indices to zero-based
        occupied.insert({x, y});
        
        // Checking all possible positions that can capture this piece
        vector<pair<long long, long long>> directions = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };
        for (auto& dir : directions) {
            long long nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                occupied.insert({nx, ny});
            }
        }
    }

    cout << n * n - occupied.size() << '\n';

    return 0;
}