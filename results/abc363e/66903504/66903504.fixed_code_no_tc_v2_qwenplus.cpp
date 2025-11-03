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
    vector<vector<pair<int,int>>> cells(100001);
    rep(i,H)rep(j,W){
        cells[A[i][j]].pb({i,j});
    }
    
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    // Process year by year
    for(int year = 1; year <= Y; year++){
        // Add all cells with elevation <= current sea level that haven't been processed yet
        for(auto [i,j] : cells[year]){
            if(!submerged[i][j]){
                // Check if this cell is connected to the sea (on border or adjacent to submerged cell)
                bool connected_to_sea = false;
                
                if(i == 0 || i == H-1 || j == 0 || j == W-1){
                    connected_to_sea = true;
                } else {
                    // Check neighbors
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
                }
                
                if(connected_to_sea){
                    // Use BFS to flood all connected cells with elevation <= year
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    submerged[i][j] = true;
                    remaining--;
                    
                    while(!q.empty()){
                        auto [ci,cj] = q.front(); q.pop();
                        
                        rep(k,4){
                            int ni = ci + dx[k];
                            int nj = cj + dy[k];
                            if(ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj] && A[ni][nj] <= year){
                                submerged[ni][nj] = true;
                                remaining--;
                                q.push({ni,nj});
                            }
                        }
                    }
                }
            }
        }
        
        cout << remaining << endl;
    }
}