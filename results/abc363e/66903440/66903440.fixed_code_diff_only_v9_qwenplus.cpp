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
    
    // Store cells by their elevation
    vector<vector<pair<int,int>>> cells_at_elevation(100001);
    rep(i,H)rep(j,W){
        cells_at_elevation[A[i][j]].pb({i,j});
    }
    
    int ans = H*W;
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    queue<pair<int,int>> q;
    
    // Process each year from 1 to Y
    for(int y = 1; y <= Y; y++){
        // Add all boundary cells with elevation <= y that haven't been processed
        if(y == 1){
            // Initialize: add all boundary cells with elevation <= current sea level
            rep(i,H) rep(j,W) {
                if((i == 0 || i == H-1 || j == 0 || j == W-1) && A[i][j] <= y && !submerged[i][j]){
                    submerged[i][j] = true;
                    q.push({i,j});
                    ans--;
                }
            }
        }
        
        // Add all non-boundary cells that have elevation exactly y and are not yet submerged
        for(auto [i,j] : cells_at_elevation[y]){
            if(!submerged[i][j] && !(i == 0 || i == H-1 || j == 0 || j == W-1)){
                // Check if this cell is connected to the sea (via already submerged cells)
                bool connected_to_sea = false;
                rep(k,4){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni >= 0 && ni < H && nj >= 0 && nj < W){
                        if(submerged[ni][nj]){
                            connected_to_sea = true;
                            break;
                        }
                    }
                }
                if(connected_to_sea){
                    submerged[i][j] = true;
                    q.push({i,j});
                    ans--;
                }
            }
        }
        
        // Flood fill from newly submerged cells
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            rep(k,4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj] && A[ni][nj] <= y){
                    submerged[ni][nj] = true;
                    q.push({ni,nj});
                    ans--;
                }
            }
        }
        
        cout << ans << endl;
    }
}