#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int main(){
    ll h,w,y;cin >> h >> w >> y;
    vector<vector<ll>> room(h,vector<ll>(w));
    rep(i,h) rep(j,w) cin >> room[i][j];
    
    // Create a list of all cells with their elevations
    vector<tuple<ll,ll,ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    
    // Sort by elevation in ascending order
    sort(cells.begin(), cells.end());
    
    vector<vector<bool>> submerged(h, vector<bool>(w, false));
    ll remaining = h * w;
    ll idx = 0;
    
    // Process each year
    for(ll year = 1; year <= y; year++) {
        // Submerge all cells with elevation <= current sea level (year)
        while(idx < cells.size() && get<0>(cells[idx]) <= year) {
            ll r = get<1>(cells[idx]);
            ll c = get<2>(cells[idx]);
            idx++;
            
            if(submerged[r][c]) continue;
            
            // Check if this cell is on the boundary or adjacent to already submerged cell
            bool should_submerge = false;
            
            // If on boundary, it will be submerged
            if(r == 0 || r == h-1 || c == 0 || c == w-1) {
                should_submerge = true;
            } else {
                // Check if adjacent to any submerged cell
                for(ll k = 0; k < 4; k++) {
                    ll nr = r + dx[k];
                    ll nc = c + dy[k];
                    if(nr >= 0 && nr < h && nc >= 0 && nc < w && submerged[nr][nc]) {
                        should_submerge = true;
                        break;
                    }
                }
            }
            
            if(should_submerge) {
                // Use BFS to flood fill from this cell
                queue<pair<ll,ll>> q;
                q.push({r,c});
                submerged[r][c] = true;
                remaining--;
                
                while(!q.empty()) {
                    auto [cr, cc] = q.front(); q.pop();
                    
                    for(ll k = 0; k < 4; k++) {
                        ll nr = cr + dx[k];
                        ll nc = cc + dy[k];
                        
                        if(nr >= 0 && nr < h && nc >= 0 && nc < w && !submerged[nr][nc] && room[nr][nc] <= year) {
                            submerged[nr][nc] = true;
                            remaining--;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        
        cout << remaining << endl;
    }
}