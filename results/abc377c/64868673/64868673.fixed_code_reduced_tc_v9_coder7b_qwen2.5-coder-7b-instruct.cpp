#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    // Directions for capturing moves
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    set<pair<long long, long long>> occupied;
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    // Check each cell to see if it's safe to place a piece
    long long safe_cells = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            bool is_safe = true;
            for (int d = 0; d < 8; ++d) {
                long long x = i + dx[d], y = j + dy[d];
                if (x >= 1 && x <= n && y >= 1 && y <= n && occupied.count({x, y})) {
                    is_safe = false;
                    break;
                }
            }
            if (is_safe) {
                ++safe_cells;
            }
        }
    }

    cout << safe_cells << endl;
    return 0;
}