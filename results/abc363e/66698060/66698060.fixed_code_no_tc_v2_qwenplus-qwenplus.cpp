#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvl vector<vector<ll>>

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vl heights(y + 2, 0); // heights[i] = remaining area at year i
    vvl grid(h, vl(w));
    rep(i, h) rep(j, w) {
        cin >> grid[i][j];
    }

    // For each year, output the current area
    ll total_area = h * w;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vvb visited(h, vb(w, false));

    // Initialize PQ with border cells (sea level starts at 0)
    for (ll i = 0; i < h; ++i) {
        if (!visited[i][0]) {
            pq.emplace(grid[i][0], i, 0);
            visited[i][0] = true;
        }
        if (!visited[i][w-1]) {
            pq.emplace(grid[i][w-1], i, w-1);
            visited[i][w-1] = true;
        }
    }
    for (ll j = 1; j < w - 1; ++j) {
        if (!visited[0][j]) {
            pq.emplace(grid[0][j], 0, j);
            visited[0][j] = true;
        }
        if (!visited[h-1][j]) {
            pq.emplace(grid[h-1][j], h-1, j);
            visited[h-1][j] = true;
        }
    }

    vl result(y + 1); // result[i] is area after i years
    result[0] = total_area;

    ll sunk_cells = 0;
    vl year_changes(y + 2, 0); // year_changes[i] = number of cells sunk at year i

    while (!pq.empty()) {
        auto [elevation, x, y_pos] = pq.top();
        pq.pop();

        // If elevation > max year, skip
        if (elevation > y) continue;

        // Mark this cell as sunk at its elevation year
        if (year_changes[elevation] == 0) {
            // First time we process this elevation
            sunk_cells++;
            year_changes[elevation] = 1;
        } else {
            sunk_cells++;
            year_changes[elevation]++;
        }

        for (ll d = 0; d < 4; ++d) {
            ll nx = x + dx[d];
            ll ny = y_pos + dy[d];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(grid[nx][ny], nx, ny);
            }
        }
    }

    // Build results from year changes
    for (ll t = 1; t <= y; ++t) {
        result[t] = result[t - 1] - year_changes[t];
        cout << result[t] << endl;
    }

    return 0;
}