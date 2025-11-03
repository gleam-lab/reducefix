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
    vector<vector<pair<ll, ll>>> cells_at_elevation(100002); // up to 10^5 + 1
    
    // Add all border cells to respective elevation groups
    for (ll i = 0; i < h; i++) {
        cells_at_elevation[room[i][0]].push_back({i, 0});
        if (w > 1) {
            cells_at_elevation[room[i][w-1]].push_back({i, w-1});
        }
    }
    for (ll j = 1; j < w-1; j++) {
        cells_at_elevation[room[0][j]].push_back({0, j});
        if (h > 1) {
            cells_at_elevation[room[h-1][j]].push_back({h-1, j});
        }
    }
    
    // BFS setup
    vb visited(h*w, false);
    auto get_idx = [&](ll i, ll j) { return i * w + j; };
    
    ll remaining = h * w;
    
    // For each year from 1 to Y
    for (ll year = 1; year <= y; year++) {
        // Process all cells with elevation <= current sea level (year)
        queue<pair<ll, ll>> q;
        
        // Add newly exposed boundary cells
        for (auto &cell : cells_at_elevation[year]) {
            ll i = cell.first, j = cell.second;
            if (!visited[get_idx(i, j)]) {
                visited[get_idx(i, j)] = true;
                q.push({i, j});
                remaining--;
            }
        }
        
        // Flood fill from these cells
        while (!q.empty()) {
            auto [ci, cj] = q.front(); q.pop();
            
            rep(k, 4) {
                ll ni = ci + dx[k], nj = cj + dy[k];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[get_idx(ni, nj)]) {
                    // If adjacent cell has elevation <= current sea level, it also drowns
                    if (room[ni][nj] <= year) {
                        visited[get_idx(ni, nj)] = true;
                        q.push({ni, nj});
                        remaining--;
                    }
                }
            }
        }
        
        cout << remaining << endl;
    }
    
    return 0;
}