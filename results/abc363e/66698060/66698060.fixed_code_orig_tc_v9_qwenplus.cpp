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
    vector<vl> room(h,vl(w));
    rep(i,h) rep(j,w) cin >> room[i][j];
    
    // Create a list of all cells with their elevations
    vector<array<ll,3>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    
    // Sort by elevation in ascending order
    sort(cells.begin(), cells.end());
    
    // Union-Find or BFS approach: simulate from low to high elevation
    vb used(h, vb(w, false));
    ll remaining = h * w;
    ll idx = 0;
    
    // For each year from 1 to Y
    for(ll sea_level = 1; sea_level <= y; sea_level++) {
        // Add all cells with elevation <= current sea level that haven't been processed
        while(idx < cells.size() && cells[idx][0] <= sea_level) {
            ll i = cells[idx][1], j = cells[idx][2];
            if(!used[i][j]) {
                used[i][j] = true;
                remaining--;
                
                // Check if this cell is on the border or adjacent to the sea
                bool is_connected_to_sea = false;
                
                // If it's on the border, it's connected to sea
                if(i == 0 || i == h-1 || j == 0 || j == w-1) {
                    is_connected_to_sea = true;
                } else {
                    // Check neighbors - if any neighbor is already sunk, then this gets sunk too
                    rep(k,4) {
                        ll ni = i + dx[k], nj = j + dy[k];
                        if(0 <= ni && ni < h && 0 <= nj && nj < w && used[ni][nj]) {
                            is_connected_to_sea = true;
                            break;
                        }
                    }
                }
                
                // If connected to sea, propagate sinking using BFS
                if(is_connected_to_sea) {
                    queue<pair<ll,ll>> q;
                    q.push({i,j});
                    
                    while(!q.empty()) {
                        auto [ci, cj] = q.front(); q.pop();
                        
                        // Check all 4 neighbors
                        rep(k,4) {
                            ll ni = ci + dx[k], nj = cj + dy[k];
                            if(0 <= ni && ni < h && 0 <= nj && nj < w && !used[ni][nj] && room[ni][nj] <= sea_level) {
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
        
        cout << remaining << endl;
    }
}