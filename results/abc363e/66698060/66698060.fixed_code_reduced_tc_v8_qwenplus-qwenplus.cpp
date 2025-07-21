#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    ll total = h * w;

    vector<vector<ll>> A(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i)
        for (ll j = 0; j < w; ++j)
            cin >> A[i][j];

    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Push all boundary cells into the priority queue
    for (ll i = 0; i < h; ++i) {
        for (ll j : {0, w - 1}) {
            if (!visited[i][j]) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    for (ll j = 1; j < w - 1; ++j) {
        for (ll i : {0, h - 1}) {
            if (!visited[i][j]) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    ll now = 0;
    vector<ll> result(y + 1);
    result[0] = total;

    for (ll year = 1; year <= y; ++year) {
        while (!pq.empty() && pq.top()[0] <= year) {
            ll val = pq.top()[0];
            ll x = pq.top()[1];
            ll y_coord = pq.top()[2];
            pq.pop();

            if (!visited[x][y_coord]) continue;
            total--;
            visited[x][y_coord] = false;  // Mark as submerged

            for (ll d = 0; d < 4; ++d) {
                ll nx = x + dx[d];
                ll ny = y_coord + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if (!visited[nx][ny]) {
                        pq.push({A[nx][ny], nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        result[year] = total;
    }

    for (ll i = 1; i <= y; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}