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

    // Binary matrix to track if a cell is submerged
    vector<vector<bool>> submerged(h, vector<bool>(w, false));

    // Priority queue to process cells in order of their elevation
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    // Mark boundary cells and push them into the priority queue
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({A[i][j], i, j});
                submerged[i][j] = true;
            }
        }
    }

    ll remaining = h * w;
    vector<ll> result(y + 2); // Store results for each year

    // Simulate year-by-year
    for (ll year = 1; year <= y; ++year) {
        while (!pq.empty() && pq.top()[0] <= year) {
            ll val = pq.top()[0];
            ll x = pq.top()[1];
            ll y_coord = pq.top()[2];
            pq.pop();

            if (!submerged[x][y_coord]) {
                submerged[x][y_coord] = true;
                remaining--;
            }

            for (ll d = 0; d < 4; ++d) {
                ll nx = x + dx[d];
                ll ny = y_coord + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !submerged[nx][ny]) {
                    pq.push({A[nx][ny], nx, ny});
                    submerged[nx][ny] = true;
                    remaining--;
                }
            }
        }
        result[year] = remaining;
    }

    // Output the results
    for (ll i = 1; i <= y; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}