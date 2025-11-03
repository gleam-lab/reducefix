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
    
    // Current area above sea level
    int ans = H*W;
    // Visited array to track sunk cells
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    
    // We'll process sinking in increasing order of elevation
    // Group cells by their elevation
    vector<vector<pair<int,int>>> cells_at_elevation(100001);
    
    // Add border cells to be processed first
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                cells_at_elevation[A[i][j]].push_back({i,j});
                sunk[i][j] = true;
                ans--;
            }
        }
    }
    
    // For each year from 1 to Y, simulate the sea level rise
    queue<pair<int,int>> q;
    
    for(int y = 1; y <= Y; y++) {
        // Add all cells with elevation <= y that are on the border or connected via sinking
        for(auto &p : cells_at_elevation[y]) {
            if (!sunk[p.first][p.second]) continue; // Already processed
            q.push(p);
        }
        
        // BFS to propagate sinking
        while(!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            
            rep(k,4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    if (!sunk[ni][nj] && A[ni][nj] <= y) {
                        sunk[ni][nj] = true;
                        ans--;
                        q.push({ni,nj});
                    }
                }
            }
        }
        
        // Output current area
        cout << ans << endl;
    }
}