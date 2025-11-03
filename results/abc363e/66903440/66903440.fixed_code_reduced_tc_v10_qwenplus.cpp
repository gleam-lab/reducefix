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
    
    // Create list of cells with their elevations
    vector<tuple<int,int,int>> cells;
    rep(i,H)rep(j,W){
        cells.push_back({A[i][j], i, j});
    }
    sort(all(cells));
    
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    int idx = 0;
    for(int year = 1; year <= Y; year++){
        // Add all cells with elevation <= current sea level
        while(idx < sz(cells) && get<0>(cells[idx]) <= year){
            auto [elev, i, j] = cells[idx];
            if(!submerged[i][j]){
                submerged[i][j] = true;
                remaining--;
                
                // Use BFS to flood from this cell if it's connected to the sea
                // But we need to check connectivity properly - instead, we'll use multi-source BFS from all border cells
            }
            idx++;
        }
        
        // However, the above doesn't handle flooding propagation correctly.
        // Let's change approach: simulate from the borders using priority queue
        
        // Actually, let's reset and use a better approach:
        // We'll process in increasing order of elevation, but maintain connectivity from borders
    }
    
    // Reset approach: use event-based simulation with priority queue
    // Instead, let's do this: start from perimeter and expand inward as sea level rises
    
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Initialize with all border cells
    rep(i,H){
        rep(j,W){
            if(i == 0 || i == H-1 || j == 0 || j == W-1){
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }
    
    vector<int> result(Y+1, H*W);
    int processed = 0;
    
    while(!pq.empty() && processed < Y){
        auto [elev, i, j] = pq.top();
        pq.pop();
        
        // This cell gets submerged when sea level reaches 'elev'
        if(elev > Y) break;
        
        result[elev]--;
        
        rep(d,4){
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]){
                visited[ni][nj] = true;
                pq.push({A[ni][nj], ni, nj});
            }
        }
    }
    
    // Accumulate the results - once a cell is gone, it stays gone
    for(int y = 1; y <= Y; y++){
        result[y] = min(result[y], result[y-1]);
    }
    
    for(int y = 1; y <= Y; y++){
        cout << result[y] << '\n';
    }
}