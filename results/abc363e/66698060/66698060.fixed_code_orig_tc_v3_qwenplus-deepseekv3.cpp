#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> room[i][j];
    
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    
    // Add all border cells to the priority queue
    rep(i, h) {
        rep(j, w) {
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                pq.push({room[i][j], i, j});
                used[i][j] = true;
            }
        }
    }
    
    ll current_year = 0;
    while (current_year++ < y) {
        while (!pq.empty() && pq.top()[0] <= current_year) {
            ll val = pq.top()[0], ni = pq.top()[1], nj = pq.top()[2];
            pq.pop();
            ans--;
            
            rep(k, 4) {
                ll nexi = ni + dx[k], nexj = nj + dy[k];
                if (0 <= nexi && nexi < h && 0 <= nexj && nexj < w && !used[nexi][nexj]) {
                    pq.push({room[nexi][nexj], nexi, nexj});
                    used[nexi][nexj] = true;
                }
            }
        }
        cout << ans << endl;
    }
}