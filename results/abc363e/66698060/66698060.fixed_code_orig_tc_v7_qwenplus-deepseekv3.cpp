#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll h, w, y;
    cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    vector<vector<bool>> used(h, vector<bool>(w, false));
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> room[i][j];
        }
    }

    // Push border cells into the priority queue
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

    ll current_sea_level = 0;
    for (ll year = 1; year <= y; ++year) {
        current_sea_level = year;
        while (!pq.empty() && get<0>(pq.top()) <= current_sea_level) {
            auto [elev, i, j] = pq.top();
            pq.pop();
            ans--;
            for (ll k = 0; k < 4; ++k) {
                ll ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], ni, nj});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}