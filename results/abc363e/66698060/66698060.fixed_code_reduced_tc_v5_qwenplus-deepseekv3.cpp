#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y; cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    vector<vector<bool>> used(h, vector<bool>(w, false));
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
        }
    }

    // Push all border cells into the priority queue
    for (ll i = 0; i < h; i++) {
        if (!used[i][0]) {
            pq.push({room[i][0], i, 0});
            used[i][0] = true;
        }
        if (w > 1 && !used[i][w-1]) {
            pq.push({room[i][w-1], i, w-1});
            used[i][w-1] = true;
        }
    }
    for (ll j = 1; j < w-1; j++) {
        if (!used[0][j]) {
            pq.push({room[0][j], 0, j});
            used[0][j] = true;
        }
        if (h > 1 && !used[h-1][j]) {
            pq.push({room[h-1][j], h-1, j});
            used[h-1][j] = true;
        }
    }

    for (ll current_year = 1; current_year <= y; current_year++) {
        while (!pq.empty() && pq.top()[0] <= current_year) {
            ll val = pq.top()[0];
            ll i = pq.top()[1];
            ll j = pq.top()[2];
            pq.pop();
            ans--;

            for (ll k = 0; k < 4; k++) {
                ll ni = i + dx[k];
                ll nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], ni, nj});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}