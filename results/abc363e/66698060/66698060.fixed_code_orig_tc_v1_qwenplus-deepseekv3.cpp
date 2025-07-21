#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({room[i][j], {i, j}});
                used[i][j] = true;
            }
        }
    }

    vector<ll> res(y + 1);
    res[0] = ans;
    
    for (ll current_level = 1; current_level <= y; current_level++) {
        while (!pq.empty() && pq.top().first <= current_level) {
            auto [val, pos] = pq.top();
            auto [i, j] = pos;
            pq.pop();
            ans--;
            
            for (ll k = 0; k < 4; k++) {
                ll ni = i + dx[k], nj = j + dy[k];
                if (0 <= ni && ni < h && 0 <= nj && nj < w && !used[ni][nj]) {
                    pq.push({room[ni][nj], {ni, nj}});
                    used[ni][nj] = true;
                }
            }
        }
        res[current_level] = ans;
    }
    
    for (ll i = 1; i <= y; i++) {
        cout << res[i] << endl;
    }
}