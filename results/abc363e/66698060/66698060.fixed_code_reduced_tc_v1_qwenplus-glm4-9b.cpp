#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)

ll h, w, y;
vector<vector<ll>> arr;
vector<vector<bool>> visited;

void sink(ll i, ll j) {
    visited[i][j] = true;
    arr[i][j]--;
    for (ll k = 0; k < 4; ++k) {
        ll ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj] && arr[ni][nj] >= 0) {
            sink(ni, nj);
        }
    }
}

int main() {
    rep(i, h) {
        arr.push_back(vector<ll>(w));
        visited.push_back(vector<bool>(w, false));
    }
    
    cin >> h >> w >> y;
    rep(i, h) {
        rep(j, w) {
            cin >> arr[i][j];
        }
    }

    ll initial_area = 0;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    rep(i, h) {
        rep(j, w) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink(i, j);
            }
            if (!visited[i][j] && arr[i][j] > 0) {
                initial_area += arr[i][j];
            }
        }
    }

    // Initial sea level is 0
    ll sea_level = 0;
    while (sea_level < y) {
        while (!pq.empty()) {
            auto [current_level, i, j] = pq.top();
            pq.pop();
            if (current_level <= sea_level) continue;
            arr[i][j] = -1;
            // Sink the neighbors
            for (ll k = 0; k < 4; ++k) {
                ll ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && arr[ni][nj] >= 0 && !visited[ni][nj]) {
                    pq.push({arr[ni][nj], ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
        sea_level++;
    }

    ll remaining_area = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if (!visited[i][j] && arr[i][j] >= 0) {
                remaining_area += arr[i][j];
            }
        }
    }

    cout << remaining_area << endl;

    return 0;
}