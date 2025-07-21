#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vector<vector<ll>> room(h, vector<ll>(w));
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cin >> room[i][j];
        }
    }
    
    // Add border cells to priority queue
    for (ll i = 0; i < h; i++) {
        pq.push({room[i][0], {i, 0}});
        used[i][0] = true;
        if (w > 1) {
            pq.push({room[i][w-1], {i, w-1}});
            used[i][w-1] = true;
        }
    }
    for (ll j = 1; j < w-1; j++) {
        pq.push({room[0][j], {0, j}});
        used[0][j] = true;
        if (h > 1) {
            pq.push({room[h-1][j], {h-1, j}});
            used[h-1][j] = true;
        }
    }
    
    ll remaining = h * w;
    vector<ll> result(y + 1, remaining);
    
    for (ll current_level = 1; current_level <= y; current_level++) {
        while (!pq.empty() && pq.top().first <= current_level) {
            auto cell = pq.top();
            pq.pop();
            remaining--;
            
            for (ll k = 0; k < 4; k++) {
                ll ni = cell.second.first + dx[k];
                ll nj = cell.second.second + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !used[ni][nj]) {
                    used[ni][nj] = true;
                    pq.push({room[ni][nj], {ni, nj}});
                }
            }
        }
        result[current_level] = remaining;
    }
    
    for (ll i = 1; i <= y; i++) {
        cout << result[i] << endl;
    }
    return 0;
}