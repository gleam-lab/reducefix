#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int main(){
    ll h,w,y;cin >> h >> w >> y;
    vector<vector<ll>> room(h,vector<ll>(w));
    rep(i,h) rep(j,w) cin >> room[i][j];
    
    // Store all cells with their elevation and position
    vector<tuple<ll,ll,ll>> cells;
    rep(i,h) rep(j,w) {
        cells.push_back({room[i][j], i, j});
    }
    sort(cells.begin(), cells.end());
    
    vector<vector<bool>> submerged(h, vector<bool>(w, false));
    ll remaining = h * w;
    ll idx = 0;
    
    for (ll year = 1; year <= y; year++) {
        // Process all cells with elevation <= current sea level
        while (idx < cells.size() && get<0>(cells[idx]) <= year) {
            ll i = get<1>(cells[idx]);
            ll j = get<2>(cells[idx]);
            idx++;
            
            if (submerged[i][j]) continue;
            
            // Check if this cell is connected to the sea (boundary or already submerged neighbor)
            bool connected_to_sea = false;
            
            // Check if on boundary
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                connected_to_sea = true;
            } else {
                // Check neighbors
                for (ll k = 0; k < 4; k++) {
                    ll ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w && submerged[ni][nj]) {
                        connected_to_sea = true;
                        break;
                    }
                }
            }
            
            if (connected_to_sea) {
                // Flood fill from this cell
                queue<pair<ll,ll>> q;
                q.push({i, j});
                submerged[i][j] = true;
                remaining--;
                
                while (!q.empty()) {
                    auto [ci, cj] = q.front(); q.pop();
                    
                    for (ll k = 0; k < 4; k++) {
                        ll ni = ci + dx[k], nj = cj + dy[k];
                        if (ni >= 0 && ni < h && nj >= 0 && nj < w && !submerged[ni][nj] && room[ni][nj] <= year) {
                            submerged[ni][nj] = true;
                            remaining--;
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }
        
        cout << remaining << endl;
    }
}