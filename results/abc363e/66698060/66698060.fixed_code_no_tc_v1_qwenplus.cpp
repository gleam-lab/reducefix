#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    
    vector<vl> room(h, vl(w));
    rep(i, h) rep(j, w) cin >> room[i][j];
    
    // Store cells by their elevation
    vector<vector<pair<ll, ll>>> cells(100001); // max elevation is 10^5
    rep(i, h) rep(j, w) {
        cells[room[i][j]].push_back({i, j});
    }
    
    ll remaining = h * w;
    vb visited(h * w, false); // flattened 2D grid
    
    // Function to convert 2D coordinate to 1D index
    auto idx = [&](ll i, ll j) { return i * w + j; };
    
    // Process each year from 1 to Y
    for (ll year = 1; year <= y; year++) {
        // Add all cells with elevation <= current sea level (year)
        for (auto& p : cells[year]) {
            ll i = p.first, j = p.second;
            if (!visited[idx(i, j)]) {
                // Use BFS to flood this cell and connected low-elevation cells
                queue<pair<ll, ll>> q;
                if (room[i][j] <= year) {
                    visited[idx(i, j)] = true;
                    q.push({i, j});
                    remaining--;
                    
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        ll ci = cur.first, cj = cur.second;
                        
                        rep(k, 4) {
                            ll ni = ci + dx[k], nj = cj + dy[k];
                            if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                                if (!visited[idx(ni, nj)] && room[ni][nj] <= year) {
                                    visited[idx(ni, nj)] = true;
                                    q.push({ni, nj});
                                    remaining--;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        cout << remaining << endl;
    }
}