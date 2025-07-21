#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y; cin >> h >> w >> y;
    vector<vector<ll>> room(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> room[i][j];
        }
    }

    // Calculate the initial number of cells that are above the initial sea level
    ll initial_area = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (room[i][j] > 0) {
                ++initial_area;
            }
        }
    }

    // Process each year
    for (ll year = 0; year < y; ++year) {
        ll new_sunk_cells = 0;
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        // Find cells that will sink this year
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (room[i][j] <= year && !visited[i][j]) {
                    // Perform DFS to find all cells that will sink
                    stack<pair<ll, ll>> stack;
                    stack.push({i, j});
                    visited[i][j] = true;

                    while (!stack.empty()) {
                        auto [x, y] = stack.top();
                        stack.pop();
                        if (room[x][y] <= year) {
                            ++new_sunk_cells;
                            for (ll k = 0; k < 4; ++k) {
                                ll nx = x + dx[k], ny = y + dy[k];
                                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && room[nx][ny] <= year) {
                                    visited[nx][ny] = true;
                                    stack.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
        }

        // Apply the sinking to the room grid
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (room[i][j] <= year) {
                    room[i][j] = 0;
                    --initial_area;
                }
            }
        }

        // Output the remaining area of the island after the current year
        cout << initial_area - new_sunk_cells << endl;
    }

    return 0;
}