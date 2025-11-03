#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    
    vector<vl> room(h, vl(w));
    rep(i, h) rep(j, w) cin >> room[i][j];
    
    // Store cells by their elevation for processing in increasing order
    vector<vector<pair<ll, ll>>> cellsByElevation(100001); // A_{i,j} up to 10^5
    rep(i, h) rep(j, w) {
        cellsByElevation[room[i][j]].push_back({i, j});
    }
    
    ll remaining = h * w;
    vb visited(h * w, false); // flattened 2D grid: index = i * w + j
    
    // Process each year from 1 to Y
    for (ll year = 1; year <= y; year++) {
        // Add all cells with elevation == year that haven't been visited
        for (auto &p : cellsByElevation[year]) {
            ll i = p.first, j = p.second;
            ll idx = i * w + j;
            if (!visited[idx]) {
                // Check if this cell is connected to the sea via already submerged cells
                // We do BFS/DFS only if it's not yet submerged
                queue<pair<ll, ll>> q;
                vector<pair<ll, ll>> component;
                
                // Start BFS to find all connected cells with elevation <= year
                if (room[i][j] <= year) {
                    q.push({i, j});
                    visited[idx] = true;
                    component.push_back({i, j});
                    
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        ll ci = cur.first, cj = cur.second;
                        
                        rep(k, 4) {
                            ll ni = ci + dx[k], nj = cj + dy[k];
                            if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                                ll nidx = ni * w + nj;
                                if (!visited[nidx] && room[ni][nj] <= year) {
                                    visited[nidx] = true;
                                    q.push({ni, nj});
                                    component.push_back({ni, nj});
                                }
                            }
                        }
                    }
                    
                    remaining -= component.size();
                }
            }
        }
        
        cout << remaining << endl;
    }
}