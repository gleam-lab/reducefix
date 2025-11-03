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
    
    // Create a list of all cells with their elevations
    vector<tuple<int,int,int>> cells;
    rep(i,H)rep(j,W){
        cells.push_back({A[i][j],i,j});
    }
    
    // Sort by elevation in ascending order
    sort(all(cells));
    
    vector<vector<bool>> submerged(H,vector<bool>(W,false));
    int remaining = H*W;
    
    // Process year by year
    int cell_idx = 0;
    
    for(int y=1;y<=Y;y++){
        // Submerge all cells with elevation <= y that are connected to the sea
        // Start from border cells and flood fill
        queue<pair<int,int>> q;
        
        // Add newly exposed border cells (that haven't been submerged yet)
        while(cell_idx < cells.size() && get<0>(cells[cell_idx]) <= y){
            auto [elev,i,j] = cells[cell_idx];
            if(!submerged[i][j]){
                // Check if this cell is on the border or adjacent to already submerged cell
                bool is_connected = (i==0 || i==H-1 || j==0 || j==W-1);
                
                if(!is_connected){
                    // Check if adjacent to any submerged cell
                    rep(dir,4){
                        int ni = i + dx[dir];
                        int nj = j + dy[dir];
                        if(ni>=0 && ni<H && nj>=0 && nj<W && submerged[ni][nj]){
                            is_connected = true;
                            break;
                        }
                    }
                }
                
                if(is_connected){
                    q.push({i,j});
                    submerged[i][j] = true;
                    remaining--;
                }
            }
            cell_idx++;
        }
        
        // Flood fill from the initially connected cells
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            
            rep(dir,4){
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if(ni>=0 && ni<H && nj>=0 && nj<W && !submerged[ni][nj] && A[ni][nj] <= y){
                    submerged[ni][nj] = true;
                    remaining--;
                    q.push({ni,nj});
                }
            }
        }
        
        cout<<remaining<<endl;
    }
}