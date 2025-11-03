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
    // Visited marker: true means still above water
    vector<vector<bool>> visited(H, vector<bool>(W, true));
    
    // Queue for events: we'll process cells when sea level reaches their threshold
    // Instead of multiple queues, use one queue and simulate year by year
    queue<pair<int,int>> q;
    
    // Initialize: all border cells will be submerged when sea level >= their height
    rep(i,H) rep(j,W) {
        if(i == 0 || i == H-1 || j == 0 || j == W-1) {
            if(A[i][j] <= 1) {
                visited[i][j] = false;
                q.push({i,j});
                ans--;
            }
        }
    }
    
    // We'll store cells that will be checked in future years
    vector<vector<pair<int,int>>> future(100010); // max elevation is 10^5
    
    // Add border cells to future events if they don't sink immediately
    rep(i,H) rep(j,W) {
        if((i == 0 || i == H-1 || j == 0 || j == W-1) && visited[i][j]) {
            future[A[i][j]].push_back({i,j});
        }
    }
    
    // Process each year
    for(int y = 1; y <= Y; y++) {
        // Add all cells that start sinking this year
        for(auto [i,j] : future[y]) {
            if(visited[i][j]) {
                visited[i][j] = false;
                q.push({i,j});
                ans--;
            }
        }
        
        // Flood fill from all currently sinking cells
        while(!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            
            rep(k,4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && visited[ni][nj]) {
                    // This adjacent cell sinks if its elevation <= current sea level
                    if(A[ni][nj] <= y) {
                        visited[ni][nj] = false;
                        ans--;
                        q.push({ni,nj});
                    }
                }
            }
        }
        
        cout << ans << endl;
        
        // After processing year y, any remaining border cells with A[i][j] == y+1
        // will be added next year, but we already pre-added them to future.
        // Clear the processed future events to save memory (optional)
        vector<pair<int,int>>().swap(future[y]);
    }
    
    return 0;
}