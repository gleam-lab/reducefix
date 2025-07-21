#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    ll h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<ll>> grid(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    for (ll sea_level = 1; sea_level <= y; ++sea_level) {
        queue<pair<ll, ll>> q;
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (!visited[i][j] && grid[i][j] <= sea_level) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                ll nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= sea_level) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (grid[i][j] > sea_level) {
                    grid[i][j]--;
                } else {
                    grid[i][j] = 0;
                }
            }
        }

        ll remaining_area = 0;
        for (ll i = 0; i < h; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (grid[i][j] > 0) {
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << '\n';
    }

    return 0;
}