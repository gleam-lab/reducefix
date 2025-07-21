#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> room[i][j];
        }
    }
    
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    
    for (ll i = 0; i < h; ++i) {
        pq.push({room[i][0], {i, 0}});
        used[i][0] = true;
        if (w > 1) {
            pq.push({room[i][w-1], {i, w-1}});
            used[i][w-1] = true;
        }
    }
    for (ll j = 1; j < w-1; ++j) {
        pq.push({room[0][j], {0, j}});
        used[0][j] = true;
        if (h > 1) {
            pq.push({room[h-1][j], {h-1, j}});
            used[h-1][j] = true;
        }
    }
    
    ll current_sea_level = 0;
    for (ll year = 1; year <= y; ++year) {
        current_sea_level = year;
        while (!pq.empty() && pq.top().first <= current_sea_level) {
            auto current = pq.top();
            pq.pop();
            ll i = current.second.first;
            ll j = current.second.second;
            ans--;
            for (ll k = 0; k < 4; ++k) {
                ll ni = i + dx[k];
                ll nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], {ni, nj}});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}