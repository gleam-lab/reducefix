#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
        }
    }
    
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    
    // Push all border cells into the priority queue
    for (ll i = 0; i < h; i++) {
        pq.push({room[i][0], i, 0});
        used[i][0] = true;
        if (w > 1) {
            pq.push({room[i][w-1], i, w-1});
            used[i][w-1] = true;
        }
    }
    for (ll j = 1; j < w-1; j++) {
        pq.push({room[0][j], 0, j});
        used[0][j] = true;
        if (h > 1) {
            pq.push({room[h-1][j], h-1, j});
            used[h-1][j] = true;
        }
    }
    
    for (ll current_level = 1; current_level <= y; current_level++) {
        while (!pq.empty() && pq.top()[0] <= current_level) {
            ll ni = pq.top()[1], nj = pq.top()[2];
            pq.pop();
            ans--;
            
            for (ll k = 0; k < 4; k++) {
                ll nexi = ni + dx[k], nexj = nj + dy[k];
                if (0 <= nexi && nexi < h && 0 <= nexj && nexj < w && !used[nexi][nexj]) {
                    pq.push({room[nexi][nexj], nexi, nexj});
                    used[nexi][nexj] = true;
                }
            }
        }
        cout << ans << '\n';
        if (ans == 0) {
            // If the island is completely submerged, the rest will also be 0
            for (current_level++; current_level <= y; current_level++) {
                cout << 0 << '\n';
            }
            return 0;
        }
    }
    return 0;
}