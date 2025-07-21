#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, Y;
    cin >> h >> w >> Y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    vector<vector<bool>> used(h, vector<bool>(w, false));
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
        }
    }

    for (ll i = 0; i < h; i++) {
        pq.push({room[i][0], {i, 0}});
        used[i][0] = true;
        pq.push({room[i][w - 1], {i, w - 1}});
        used[i][w - 1] = true;
    }
    for (ll j = 1; j < w - 1; j++) {
        pq.push({room[0][j], {0, j}});
        used[0][j] = true;
        pq.push({room[h - 1][j], {h - 1, j}});
        used[h - 1][j] = true;
    }

    ll now = 1;
    while (now <= Y) {
        while (!pq.empty() && pq.top().first <= now) {
            auto current = pq.top();
            pq.pop();
            ll ni = current.second.first, nj = current.second.second;
            ans--;
            for (ll k = 0; k < 4; k++) {
                ll nexi = ni + dx[k], nexj = nj + dy[k];
                if (nexi >= 0 && nexi < h && nexj >= 0 && nexj < w && !used[nexi][nexj]) {
                    used[nexi][nexj] = true;
                    pq.push({room[nexi][nexj], {nexi, nexj}});
                }
            }
        }
        cout << ans << '\n';
        now++;
    }
    return 0;
}