#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define pr pair<int, int>

int main() {
    ll h, w, y; cin >> h >> w >> y;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    // Priority queue for processing sections by elevation
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    
    // Mark sections that are next to the sea or are submerged
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    // Initialize the priority queue with edge sections
    rep(i, h) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] < y) {
                pq.push({a[i][j], i});
                visited[i][j] = true;
            }
        }
        if (i != 0) {
            pq.push({a[i][0], i});
            visited[i][0] = true;
        }
        if (i != h - 1) {
            pq.push({a[i][w - 1], i});
            visited[i][w - 1] = true;
        }
    }
    for (int j = 0; j < w; ++j) {
        if (j != 0) {
            pq.push({a[0][j], 0});
            visited[0][j] = true;
        }
        if (j != w - 1) {
            pq.push({a[h - 1][j], h - 1});
            visited[h - 1][j] = true;
        }
    }

    ll remaining_area = h * w; // Initial area of the island
    while (!pq.empty()) {
        ll elevation, x;
        tie(elevation, x) = pq.top(); pq.pop();
        int i = x;
        rep(j, w) if (a[i][j] > elevation && !visited[i][j]) {
            pq.push({a[i][j], i});
            visited[i][j] = true;
            remaining_area--;
        }
    }

    // Output the remaining area for each year
    for (ll year = 1; year <= y; ++year) {
        cout << remaining_area << '\n';
        // Increment the sea level
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j]) {
                    pq.push({a[i][j], i});
                    visited[i][j] = true;
                    if (a[i][j] <= year) {
                        remaining_area--;
                    }
                }
            }
        }
        // Process the priority queue for one year
        while (!pq.empty()) {
            ll elevation, x;
            tie(elevation, x) = pq.top(); pq.pop();
            int i = x;
            rep(j, w) if (a[i][j] > elevation && !visited[i][j]) {
                pq.push({a[i][j], i});
                visited[i][j] = true;
                if (a[i][j] <= year + 1) {
                    remaining_area--;
                }
            }
        }
    }

    return 0;
}