#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i = 0; i < (ll)n; i++)

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<ll>> grid(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];

    // We'll use a priority queue to simulate the rising sea level
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Start from the borders as they are the first to be submerged
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.emplace(grid[i][j], i, j);
                visited[i][j] = true;
            }
        }
    }

    ll remaining = h * w;
    vector<ll> result(y + 2); // Store results for each year
    result[0] = remaining;

    // Process using BFS with a priority queue to simulate correct sinking order
    while (!pq.empty()) {
        auto [height, x, y_coord] = pq.top();
        pq.pop();

        // If this cell's height is above current sea level, it won't sink yet
        if (height > y) continue;

        remaining--;
        result[height]--;

        for (ll dir = 0; dir < 4; ++dir) {
            ll nx = x + dx[dir];
            ll ny = y_coord + dy[dir];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(grid[nx][ny], nx, ny);
            }
        }
    }

    // Accumulate the results: if a cell disappears at year t, it also disappears in all future years
    for (ll i = 1; i <= y; ++i) {
        result[i] += result[i - 1];
        cout << result[i] << endl;
    }

    return 0;
}