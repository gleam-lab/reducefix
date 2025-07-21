#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define pii pair<int, int>
#define F first
#define S second

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<ll>> A(h, vector<ll>(w));
    rep(i,h) rep(j,w) cin >> A[i][j];

    // Create a list of all cells with their values
    vector<tuple<ll, ll, ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({A[i][j], i, j});
    }

    // Sort cells by elevation
    sort(cells.begin(), cells.end());

    // visited matrix
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Initialize queue with border cells
    queue<pii> q;
    rep(i,h) {
        if (!visited[i][0]) {
            visited[i][0] = true;
            q.push({i, 0});
        }
        if (!visited[i][w-1]) {
            visited[i][w-1] = true;
            q.push({i, w-1});
        }
    }
    rep(j, w) {
        if (!visited[0][j]) {
            visited[0][j] = true;
            q.push({0, j});
        }
        if (!visited[h-1][j]) {
            visited[h-1][j] = true;
            q.push({h-1, j});
        }
    }

    ll remaining = h * w;
    vector<ll> result(y + 1);
    result[0] = remaining;

    ll idx = 0;
    ll curr_year = 1;

    // Process each year
    while (curr_year <= y) {
        // Add cells that sink this year
        while (idx < cells.size() && get<0>(cells[idx]) == curr_year) {
            ll x = get<1>(cells[idx]);
            ll y_coord = get<2>(cells[idx]);
            A[x][y_coord] = -1; // Mark as sunk
            idx++;
        }

        // BFS to find connected cells that also sink
        queue<pii> bq;
        while (!q.empty()) {
            auto [x, y_coord] = q.front();
            q.pop();
            if (A[x][y_coord] != -1) continue; // Only process sunk cells

            for (ll d = 0; d < 4; d++) {
                ll nx = x + dx[d];
                ll ny = y_coord + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (A[nx][ny] == -1 || A[nx][ny] <= curr_year) {
                        A[nx][ny] = -1; // Sink this cell
                        bq.push({nx, ny});
                    } else {
                        q.push({nx, ny});
                    }
                }
            }
        }

        // Update the main queue with newly sunk cells
        while (!bq.empty()) {
            auto [x, y_coord] = bq.front();
            bq.pop();
            remaining--;
            for (ll d = 0; d < 4; d++) {
                ll nx = x + dx[d];
                ll ny = y_coord + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (A[nx][ny] == -1 || A[nx][ny] <= curr_year) {
                        A[nx][ny] = -1;
                        bq.push({nx, ny});
                    } else {
                        q.push({nx, ny});
                    }
                }
            }
        }

        result[curr_year] = remaining;
        curr_year++;
    }

    for (ll i = 1; i <= y; i++) {
        cout << result[i] << endl;
    }

    return 0;
}