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
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({room[i][j], i, j});
                used[i][j] = true;
            }
        }
    }

    for (ll now = 1; now <= y; now++) {
        while (!pq.empty() && pq.top()[0] <= now) {
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
        cout << ans << endl;
    }
    return 0;
}