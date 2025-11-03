#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using ll=int64_t;
using ld=long double;
int inf=1000000001;
ll INF=1e18;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(x) (ll)x.size()
template<typename T>bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int H,W,Y;
    cin>>H>>W>>Y;
    vector<vector<int>>A(H,vector<int>(W));
    rep(i,H)rep(j,W)cin>>A[i][j];
    
    // Create events: when each cell gets submerged
    vector<vector<int>> events(Y+1);
    
    // Mark border cells as initially submerged
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    queue<pair<int,int>> q;
    
    // Add all border cells to the initial queue
    rep(i,H) {
        rep(j,W) {
            if(i == 0 || i == H-1 || j == 0 || j == W-1) {
                submerged[i][j] = true;
                if(A[i][j] <= Y) {
                    events[A[i][j]].push_back({i,j});
                }
                q.push({i,j});
            }
        }
    }
    
    // Process the initial BFS to find all cells that will eventually be submerged
    while(!q.empty()) {
        auto [i,j] = q.front(); q.pop();
        
        rep(k,4) {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                // This cell will be submerged when sea level reaches max(A[ni][nj], A[i][j])
                // But we need to process it when its own elevation is reached
                if(A[ni][nj] <= Y) {
                    events[A[ni][nj]].push_back({ni,nj});
                }
                submerged[ni][nj] = true;
                q.push({ni,nj});
            }
        }
    }
    
    // Reset submerged state for simulation
    vector<vector<bool>> is_submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    // Process year by year
    queue<pair<int,int>> current_q;
    
    // First, mark all border cells as submerged at their elevation time
    rep(i,H) rep(j,W) {
        if((i == 0 || i == H-1 || j == 0 || j == W-1)) {
            if(A[i][j] <= 0) {
                if(!is_submerged[i][j]) {
                    is_submerged[i][j] = true;
                    remaining--;
                    current_q.push({i,j});
                }
            }
        }
    }
    
    rep(y, Y) {
        int year = y + 1;
        
        // Add all cells with elevation == year that are on the "boundary" of the island
        for(auto [i,j] : events[year]) {
            if(!is_submerged[i][j]) {
                // Check if this cell is adjacent to a submerged cell or is on border
                bool can_submerge = (i == 0 || i == H-1 || j == 0 || j == W-1);
                if(!can_submerge) {
                    rep(k,4) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if(ni >= 0 && ni < H && nj >= 0 && nj < W && is_submerged[ni][nj]) {
                            can_submerge = true;
                            break;
                        }
                    }
                }
                
                if(can_submerge) {
                    is_submerged[i][j] = true;
                    remaining--;
                    current_q.push({i,j});
                }
            }
        }
        
        // Flood fill from newly submerged cells
        while(!current_q.empty()) {
            auto [i,j] = current_q.front(); current_q.pop();
            
            rep(k,4) {
                int ni = i + dx[k], nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && !is_submerged[ni][nj] && A[ni][nj] <= year) {
                    is_submerged[ni][nj] = true;
                    remaining--;
                    current_q.push({ni,nj});
                }
            }
        }
        
        cout << remaining << '\n';
    }
}