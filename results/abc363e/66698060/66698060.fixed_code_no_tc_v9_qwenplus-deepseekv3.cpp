#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll h, w, Y;
    cin >> h >> w >> Y;
    vector<vector<ll>> room(h, vector<ll>(w));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> room[i][j];
        }
    }
    
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    
    // Add border sections to the priority queue
    for (ll i = 0; i < h; ++i) {
        if (!used[i][0]) {
            pq.push({room[i][0], i, 0});
            used[i][0] = true;
        }
        if (w > 1 && !used[i][w-1]) {
            pq.push({room[i][w-1], i, w-1});
            used[i][w-1] = true;
        }
    }
    for (ll j = 1; j < w-1; ++j) {
        if (!used[0][j]) {
            pq.push({room[0][j], 0, j});
            used[0][j] = true;
        }
        if (h > 1 && !used[h-1][j]) {
            pq.push({room[h-1][j], h-1, j});
            used[h-1][j] = true;
        }
    }
    
    ll total = h * w;
    vector<ll> sink_count(Y + 2, 0); // 1-based to Y
    
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        ll year = top[0], i = top[1], j = top[2];
        if (year > Y) break;
        sink_count[year]++;
        for (ll k = 0; k < 4; ++k) {
            ll ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                pq.push({room[ni][nj], ni, nj});
                used[ni][nj] = true;
            }
        }
    }
    
    vector<ll> prefix(Y + 1, 0);
    for (ll i = 1; i <= Y; ++i) {
        prefix[i] = prefix[i-1] + sink_count[i];
    }
    
    for (ll i = 1; i <= Y; ++i) {
        cout << total - prefix[i] << "\n";
    }
    
    return 0;
}