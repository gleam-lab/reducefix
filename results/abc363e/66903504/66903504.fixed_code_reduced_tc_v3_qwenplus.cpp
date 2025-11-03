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
    
    // Create list of all cells with their elevations
    vector<tuple<int,int,int>> cells;
    rep(i,H)rep(j,W){
        cells.push_back({A[i][j], i, j});
    }
    sort(all(cells)); // Sort by elevation
    
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    // Process year by year
    int idx = 0; // pointer to next cell in sorted list
    for(int y = 1; y <= Y; y++){
        // Add all cells with elevation <= y that are on the border or connected to submerged area
        while(idx < sz(cells) && get<0>(cells[idx]) <= y){
            int h = get<1>(cells[idx]);
            int w = get<2>(cells[idx]);
            idx++;
            
            if(submerged[h][w]) continue;
            
            // Check if this cell is on border or adjacent to submerged cell
            bool should_submerge = false;
            if(h == 0 || h == H-1 || w == 0 || w == W-1){
                should_submerge = true;
            } else {
                rep(k,4){
                    int nh = h + dx[k];
                    int nw = w + dy[k];
                    if(nh >= 0 && nh < H && nw >= 0 && nw < W){
                        if(submerged[nh][nw]){
                            should_submerge = true;
                            break;
                        }
                    }
                }
            }
            
            if(should_submerge){
                // Flood fill from this cell
                queue<pair<int,int>> q;
                q.push({h,w});
                submerged[h][w] = true;
                remaining--;
                
                while(!q.empty()){
                    auto [i,j] = q.front(); q.pop();
                    rep(k,4){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj] && A[ni][nj] <= y){
                            submerged[ni][nj] = true;
                            remaining--;
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }
        
        cout << remaining << '\n';
    }
}