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
    
    // We'll process cells in order of their elevation
    vector<tuple<int,int,int>> cells; // (elevation, i, j)
    rep(i,H)rep(j,W){
        cells.emplace_back(A[i][j], i, j);
    }
    sort(all(cells));
    
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    // Process each year from 1 to Y
    int ptr = 0; // pointer to next cell to consider
    queue<pair<int,int>> q;
    
    for(int y = 1; y <= Y; y++){
        // Add all cells with elevation <= y that haven't been processed yet
        while(ptr < sz(cells) && get<0>(cells[ptr]) <= y){
            auto [elev, i, j] = cells[ptr];
            if(!submerged[i][j]){
                // Check if this cell is on the border or adjacent to a submerged cell
                bool should_submerge = false;
                if(i == 0 || i == H-1 || j == 0 || j == W-1){
                    should_submerge = true;
                } else {
                    rep(k,4){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(ni >= 0 && ni < H && nj >= 0 && nj < W && submerged[ni][nj]){
                            should_submerge = true;
                            break;
                        }
                    }
                }
                
                if(should_submerge){
                    submerged[i][j] = true;
                    q.push({i,j});
                    remaining--;
                }
            }
            ptr++;
        }
        
        // BFS to flood fill all connected cells with elevation <= y
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            
            rep(k,4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj] && A[ni][nj] <= y){
                    submerged[ni][nj] = true;
                    q.push({ni,nj});
                    remaining--;
                }
            }
        }
        
        cout << remaining << '\n';
    }
}