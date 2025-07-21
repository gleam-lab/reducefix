#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    set<pair<long long, long long>> positions;
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        positions.insert({a, b});
    }

    // Directions for knight moves
    vector<vector<long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    set<pair<long long, long long>> invalidPositions;
    for (const auto& pos : positions) {
        for (const auto& dir : directions) {
            long long x = pos.first + dir[0];
            long long y = pos.second + dir[1];
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                invalidPositions.insert({x, y});
            }
        }
    }

    cout << n * n - invalidPositions.size() << endl;
    return 0;
}