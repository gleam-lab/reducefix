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

ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int main(){
    ll h,w,y;cin >> h >> w >> y;
    vector room(h,vl(w));
    rep(i,h) rep(j,w) cin >> room[i][j];
    
    // Create a list of all cells with their elevations and coordinates
    vector<tuple<ll,ll,ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    
    // Sort by elevation in ascending order
    sort(cells.begin(), cells.end());
    
    // Union-Find or BFS simulation from low to high elevation
    vb used(h, vb(w, false));
    ll remaining = h * w;
    vector<ll> ans(y+1);
    
    ll idx = 0;
    // For each year from 1 to y
    for (ll sea_level = 1; sea_level <= y; sea_level++) {
        // Add all cells with elevation <= sea_level that haven't been processed
        while (idx < cells.size() && get<0>(cells[idx]) <= sea_level) {
            auto [elev, i, j] = cells[idx];
            if (!used[i][j]) {
                used[i][j] = true;
                remaining--;
                
                // Check if this cell is connected to the "sea" (border or already sunk neighbor)
                queue<pair<ll,ll>> q;
                bool sinks = false;
                
                // If on border, it's adjacent to sea
                if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                    sinks = true;
                } else {
                    // Check neighbors
                    rep(k,4) {
                        ll ni = i + dx[k], nj = j + dy[k];
                        if (0 <= ni && ni < h && 0 <= nj && nj < w && used[ni][nj]) {
                            sinks = true;
                            break;
                        }
                    }
                }
                
                if (sinks) {
                    // Flood fill from this cell
                    q.push({i,j});
                    while (!q.empty()) {
                        auto [ci, cj] = q.front(); q.pop();
                        rep(k,4) {
                            ll ni = ci + dx[k], nj = cj + dy[k];
                            if (0 <= ni && ni < h && 0 <= nj && nj < w && !used[ni][nj] && room[ni][nj] <= sea_level) {
                                used[ni][nj] = true;
                                remaining--;
                                q.push({ni,nj});
                            }
                        }
                    }
                }
            }
            idx++;
        }
        ans[sea_level] = remaining;
    }
    
    // Output for each year
    for (ll i = 1; i <= y; i++) {
        cout << ans[i] << endl;
    }
}