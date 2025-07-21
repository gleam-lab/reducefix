#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y; cin >> h >> w >> y;
    ll ans = h * w;
    vector<vector<ll>> room(h, vector<ll>(w));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
        }
    }

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vector<bool>> used(h, vector<bool>(w, false));

    // Add border sections to the priority queue
    for (ll i = 0; i < h; i++) {
        if (!used[i][0]) {
            pq.push({room[i][0], {i, 0}});
            used[i][0] = true;
        }
        if (!used[i][w-1]) {
            pq.push({room[i][w-1], {i, w-1}});
            used[i][w-1] = true;
        }
    }
    for (ll j = 1; j < w-1; j++) {
        if (!used[0][j]) {
            pq.push({room[0][j], {0, j}});
            used[0][j] = true;
        }
        if (!used[h-1][j]) {
            pq.push({room[h-1][j], {h-1, j}});
            used[h-1][j] = true;
        }
    }

    for (ll current_year = 1; current_year <= y; current_year++) {
        while (!pq.empty() && pq.top().first <= current_year) {
            auto top = pq.top();
            pq.pop();
            ll ni = top.second.first, nj = top.second.second;
            ans--;

            for (ll k = 0; k < 4; k++) {
                ll nexi = ni + dx[k], nexj = nj + dy[k];
                if (0 <= nexi && nexi < h && 0 <= nexj && nexj < w && !used[nexi][nexj]) {
                    pq.push({room[nexi][nexj], {nexi, nexj}});
                    used[nexi][nexj] = true;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}