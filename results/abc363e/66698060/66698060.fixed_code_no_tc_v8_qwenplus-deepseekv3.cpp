#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define vl vector<ll>
#define vb vector<bool>

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y; cin >> h >> w >> y;
    ll ans = h * w;
    vector<vl> room(h, vl(w));
    rep(i, h) rep(j, w) cin >> room[i][j];
    
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vb> used(h, vb(w, false));
    
    // Push all boundary cells into the priority queue
    rep(i, h) {
        if (!used[i][0]) {
            pq.push({room[i][0], {i, 0}});
            used[i][0] = true;
        }
        if (!used[i][w - 1]) {
            pq.push({room[i][w - 1], {i, w - 1}});
            used[i][w - 1] = true;
        }
    }
    rep(j, 1, w - 1) {
        if (!used[0][j]) {
            pq.push({room[0][j], {0, j}});
            used[0][j] = true;
        }
        if (!used[h - 1][j]) {
            pq.push({room[h - 1][j], {h - 1, j}});
            used[h - 1][j] = true;
        }
    }

    ll current_sea_level = 0;
    rep(year, 1, y + 1) {
        current_sea_level = year;
        while (!pq.empty() && pq.top().first <= current_sea_level) {
            auto cell = pq.top();
            pq.pop();
            ll i = cell.second.first, j = cell.second.second;
            ans--;
            rep(k, 4) {
                ll ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    pq.push({room[ni][nj], {ni, nj}});
                    used[ni][nj] = true;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}