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
        // Add all cells with elevation exactly y that are on the border
        for(auto [i,j] : cells_at_elevation[y]){
            if(i == 0 || i == H-1 || j == 0 || j == W-1){
                if(!submerged[i][j]){
                    submerged[i][j] = true;
                    q.push({i,j});
                    ans--;
                }
            }
        }
        
        // Flood fill from newly submerged border cells
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            
            rep(k,4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W){
                    if(!submerged[ni][nj] && A[ni][nj] <= y){
                        submerged[ni][nj] = true;
                        q.push({ni,nj});
                        ans--;
                    }
                }
            }
        }
        
        cout << ans << endl;
    }
}