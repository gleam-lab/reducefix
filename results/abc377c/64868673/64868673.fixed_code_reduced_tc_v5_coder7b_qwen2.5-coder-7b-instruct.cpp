#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    // Directions for capturing moves
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

    set<pair<int, int>> occupied;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    // Set to store all valid positions
    set<pair<int, int>> valid_positions;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool can_place = true;
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 1 && x <= n && y >= 1 && y <= n && occupied.count({x, y})) {
                    can_place = false;
                    break;
                }
            }
            if (can_place) {
                valid_positions.insert({i, j});
            }
        }
    }

    cout << valid_positions.size() << endl;
    return 0;
}