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
    vector<vector<int>> submerge_year(H, vector<int>(W, Y+1));
    queue<tuple<int,int,int>> q; // (year, i, j)
    
    // Initially, all border cells will submerge at year = A[i][j] (if <= Y)
    rep(i,H)rep(j,W){
        if(i==0 || i==H-1 || j==0 || j==W-1){
            int year = A[i][j];
            if(year <= Y){
                submerge_year[i][j] = year;
                q.push({year, i, j});
            }
        }
    }
    
    // BFS to propagate submersion
    while(!q.empty()){
        auto [yr, i, j] = q.front(); q.pop();
        
        rep(k,4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W){
                // The water level needed to reach this cell is max(current_water_level, cell_elevation)
                int required_year = max(yr, A[ni][nj]);
                if(required_year <= Y && required_year < submerge_year[ni][nj]){
                    submerge_year[ni][nj] = required_year;
                    q.push({required_year, ni, nj});
                }
            }
        }
    }
    
    // Count how many cells remain above water at each year
    vector<int> remaining(Y+1, H*W);
    vector<int> change(Y+1, 0);
    
    rep(i,H)rep(j,W){
        if(submerge_year[i][j] <= Y){
            change[submerge_year[i][j]]++;
        }
    }
    
    int current = H*W;
    for(int y = 1; y <= Y; y++){
        current -= change[y];
        cout << current << '\n';
    }
}