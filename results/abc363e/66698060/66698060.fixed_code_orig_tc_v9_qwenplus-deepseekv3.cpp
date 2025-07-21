#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll h, w, y;
    cin >> h >> w >> y;
    vector<vector<ll>> room(h, vector<ll>(w));
    vector<vector<bool>> used(h, vector<bool>(w, false));
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                pq.push({room[i][j], {i, j}});
                used[i][j] = true;
            }
        }
    }

    ll ans = h * w;
    ll current_level = 1;
    
    for (ll year = 1; year <= y; year++) {
        while (!pq.empty() && pq.top().first <= year) {
            auto cell = pq.top();
            pq.pop();
            ll i = cell.second.first;
            ll j = cell.second.second;
            
            if (room[i][j] > year) continue; // Already processed or shouldn't sink yet
            
            ans--;
            
            for (ll k = 0; k < 4; k++) {
                ll ni = i + dx[k];
                ll nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], {ni, nj}});
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}