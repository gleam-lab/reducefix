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
    
    // We'll simulate the flooding process in reverse order of elevation
    // Instead of processing year-by-year with queues, we use a priority queue or sort by elevation
    
    // Create list of all border cells and their elevations
    vector<tuple<int,int,int>> events; // (elevation, i, j)
    
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    // Add all border cells to initial events
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                events.emplace_back(A[i][j], i, j);
                submerged[i][j] = true;
            }
        }
    }
    
    // Sort events by elevation (lowest first)
    sort(all(events));
    
    // For each year, we want to output the remaining area
    vector<int> result(Y+1, remaining); // result[y] = area after y years
    
    int event_idx = 0;
    
    // Process each year from 1 to Y
    for (int year = 1; year <= Y; year++) {
        // Process all cells with elevation <= current sea level (which is 'year')
        while (event_idx < (int)events.size()) {
            auto [elev, i, j] = events[event_idx];
            if (elev > year) break;
            
            // This cell is already marked as submerged when added to events
            // But we need to check its neighbors for potential submersion
            queue<pair<int,int>> q;
            q.push({i,j});
            
            // We'll do BFS only for newly accessible submerged cells
            // But instead, let's restructure: use one BFS that propagates based on elevation
            
            event_idx++;
        }
        
        // The above approach won't work correctly because we need propagation
        
        // Let's change strategy: use multi-source Dijkstra-like approach
    }
    
    // Correct approach: Use priority queue to simulate flooding over time
    remaining = H * W;
    vector<vector<bool>> vis(H, vector<bool>(W, false));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    
    // Initialize with all border cells
    rep(i,H) rep(j,W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            pq.emplace(A[i][j], i, j);
            vis[i][j] = true;
        }
    }
    
    vector<int> ans(Y+1, H*W);
    int processed = 0;
    
    while (!pq.empty() && processed < Y) {
        auto [elev, i, j] = pq.top();
        pq.pop();
        
        // This cell gets submerged at year = elev (unless already counted)
        if (elev > Y) break;
        
        // All years from current to elev-1 have the same count
        while (processed < elev-1) {
            processed++;
            ans[processed] = remaining;
        }
        
        // At year = elev, this cell (and possibly others) get submerged
        if (ans[elev] == H*W) { // first time reaching this elevation
            ans[elev] = remaining - 1;
        } else {
            ans[elev]--;
        }
        
        remaining--;
        
        // Check neighbors
        rep(k,4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !vis[ni][nj]) {
                vis[ni][nj] = true;
                pq.emplace(A[ni][nj], ni, nj);
            }
        }
    }
    
    // Fill in remaining years
    while (processed < Y) {
        processed++;
        ans[processed] = remaining;
    }
    
    // Output for each year
    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}