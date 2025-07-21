#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll h, w, y; cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    vector<vector<bool>> used(h, vector<bool>(w, false));
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> room[i][j];
        }
    }

    for (ll i = 0; i < h; ++i) {
        if (!used[i][0]) {
            pq.push({room[i][0], i, 0});
            used[i][0] = true;
        }
        if (!used[i][w - 1]) {
            pq.push({room[i][w - 1], i, w - 1});
            used[i][w - 1] = true;
        }
    }
    for (ll j = 1; j < w - 1; ++j) {
        if (!used[0][j]) {
            pq.push({room[0][j], 0, j});
            used[0][j] = true;
        }
        if (!used[h - 1][j]) {
            pq.push({room[h - 1][j], h - 1, j});
            used[h - 1][j] = true;
        }
    }

    ll current_level = 0;
    vector<ll> results(y);
    while (current_level < y) {
        current_level++;
        while (!pq.empty()) {
            auto [elev, i, j] = pq.top();
            if (elev > current_level) break;
            pq.pop();
            ans--;
            for (ll k = 0; k < 4; ++k) {
                ll ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    pq.push({room[ni][nj], ni, nj});
                    used[ni][nj] = true;
                }
            }
        }
        results[current_level - 1] = ans;
    }

    for (ll i = 0; i < y; ++i) {
        cout << results[i] << "\n";
    }
    return 0;
}