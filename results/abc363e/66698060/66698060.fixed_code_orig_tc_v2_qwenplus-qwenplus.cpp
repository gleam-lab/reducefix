#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vector<vector<ll>> A(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }

    // Total area of the island
    ll total_area = h * w;

    // visited array to mark cells already submerged
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Priority queue to process cells by elevation
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    // Mark border cells and add them to the queue
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    // To store results
    vector<ll> result(y + 2); // year runs from 1 to Y

    // Process events in order of increasing sea level
    ll sea_level = 0;
    ll count_submerged = 0;

    while (sea_level <= y) {
        // First, process all cells with elevation <= current sea level
        while (!pq.empty() && pq.top()[0] <= sea_level) {
            ll x = pq.top()[1];
            ll y_coord = pq.top()[2];
            pq.pop();

            // Already processed
            if (visited[x][y_coord]) continue;

            visited[x][y_coord] = true;
            count_submerged++;

            // Push neighbors into queue if not visited
            for (ll d = 0; d < 4; ++d) {
                ll nx = x + dx[d];
                ll ny = y_coord + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                    pq.push({A[nx][ny], nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        // Store the remaining area
        if (sea_level >= 1) {
            result[sea_level] = total_area - count_submerged;
        }

        sea_level++;
    }

    // Output the results
    for (ll i = 1; i <= y; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}