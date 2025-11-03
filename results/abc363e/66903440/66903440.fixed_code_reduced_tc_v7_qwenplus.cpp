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
    vector<vector<pair<int,int>>> elevations(100001);
    rep(i,H)rep(j,W){
        elevations[A[i][j]].pb({i,j});
    }
    
    vector<vector<bool>> submerged(H,vector<bool>(W,false));
    int remaining = H*W;
    
    // Process each year from 1 to Y
    for(int y=1; y<=Y; y++){
        // Add all cells with elevation <= y that haven't been processed yet
        for(auto [i,j] : elevations[y]){
            if(!submerged[i][j]){
                // Check if this cell is on the border or adjacent to submerged cell
                bool should_submerge = false;
                if(i==0 || i==H-1 || j==0 || j==W-1){
                    should_submerge = true;
                } else {
                    rep(k,4){
                        int ni = i+dx[k], nj = j+dy[k];
                        if(ni>=0 && ni<H && nj>=0 && nj<W && submerged[ni][nj]){
                            should_submerge = true;
                            break;
                        }
                    }
                }
                
                if(should_submerge){
                    // BFS to flood all connected low-elevation areas
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    submerged[i][j] = true;
                    remaining--;
                    
                    while(!q.empty()){
                        auto [ci,cj] = q.front(); q.pop();
                        rep(k,4){
                            int ni = ci+dx[k], nj = cj+dy[k];
                            if(ni>=0 && ni<H && nj>=0 && nj<W && !submerged[ni][nj] && A[ni][nj] <= y){
                                submerged[ni][nj] = true;
                                remaining--;
                                q.push({ni,nj});
                            }
                        }
                    }
                }
            }
        }
        
        cout << remaining << '\n';
    }
}