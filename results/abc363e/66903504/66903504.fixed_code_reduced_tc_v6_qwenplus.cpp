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
    
    // Store cells by elevation
    vector<vector<pair<int,int>>> cells_at_level(Y+1);
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    // Add border cells to their respective elevation queues
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                if (A[i][j] <= Y) {
                    cells_at_level[A[i][j]].push_back({i,j});
                } else {
                    // This cell won't be submerged during simulation
                }
            }
        }
    }
    
    // Process year by year
    for (int y = 1; y <= Y; y++) {
        queue<pair<int,int>> q;
        
        // Add all cells with elevation exactly y that are on border or connected
        for (auto [i,j] : cells_at_level[y]) {
            if (!submerged[i][j]) {
                submerged[i][j] = true;
                q.push({i,j});
                remaining--;
            }
        }
        
        // Flood fill from newly submerged cells
        while (!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            
            rep(k,4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                    // If adjacent cell has elevation <= current sea level (y), it also submerges
                    if (A[ni][nj] <= y) {
                        submerged[ni][nj] = true;
                        q.push({ni,nj});
                        remaining--;
                    } else {
                        // For cells with higher elevation, we'll process them when sea level reaches their height
                        if (A[ni][nj] <= Y) {
                            cells_at_level[A[ni][nj]].push_back({ni,nj});
                        }
                    }
                }
            }
        }
        
        cout << remaining << '\n';
    }
}