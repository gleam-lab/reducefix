#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    vector<vector<bool>> used(h, vector<bool>(w, false));
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                pq.push({room[i][j], i, j});
                used[i][j] = true;
            }
        }
    }

    ll current_sea_level = 0;
    for (ll now = 1; now <= y; now++) {
        while (!pq.empty() && get<0>(pq.top()) <= now) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            ans--;
            
            for (ll k = 0; k < 4; k++) {
                ll ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], ni, nj});
                }
            }
        }
        cout << ans << endl;
    }
}