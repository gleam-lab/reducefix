#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll h, w, y;
    cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
        }
    }
    
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    
    // Push border cells into the priority queue
    for (ll i = 0; i < h; i++) {
        if (!used[i][0]) {
            pq.push({room[i][0], {i, 0}});
            used[i][0] = true;
        }
        if (w > 1 && !used[i][w-1]) {
            pq.push({room[i][w-1], {i, w-1}});
            used[i][w-1] = true;
        }
    }
    for (ll j = 1; j < w-1; j++) {
        if (!used[0][j]) {
            pq.push({room[0][j], {0, j}});
            used[0][j] = true;
        }
        if (h > 1 && !used[h-1][j]) {
            pq.push({room[h-1][j], {h-1, j}});
            used[h-1][j] = true;
        }
    }
    
    ll current_level = 0;
    for (ll now = 1; now <= y; now++) {
        while (!pq.empty() && pq.top().first <= now) {
            auto cell = pq.top();
            pq.pop();
            ans--;
            
            ll ni = cell.second.first;
            ll nj = cell.second.second;
            for (ll k = 0; k < 4; k++) {
                ll nexi = ni + dx[k];
                ll nexj = nj + dy[k];
                if (0 <= nexi && nexi < h && 0 <= nexj && nexj < w && !used[nexi][nexj]) {
                    used[nexi][nexj] = true;
                    pq.push({room[nexi][nexj], {nexi, nexj}});
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}