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
    
    // We'll use event-based simulation with priority queue
    // Instead of simulating year-by-year from 0, we simulate sinking events in increasing elevation order
    
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    
    // Initially, add all border cells to the priority queue
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                submerged[i][j] = true;
            }
        }
    }
    
    int remaining = H * W;
    vector<int> ans(Y+1, remaining); // ans[y] = area after y years
    
    // Process cells in increasing order of elevation
    while (!pq.empty()) {
        auto [elev, i, j] = pq.top();
        pq.pop();
        
        // This cell sinks when sea level reaches elev
        // But only update if elev <= Y
        if (elev <= Y) {
            // All years from elev onward lose this cell
            for (int y = elev; y <= Y; y++) {
                ans[y]--;
            }
            remaining--;
        }
        
        // Check neighbors
        rep(k,4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                submerged[ni][nj] = true;
                pq.push({A[ni][nj], ni, nj});
            }
        }
    }
    
    // However, the above approach over-subtracts. Let's fix by processing year-by-year properly.
    // Actually, let's rework: we want to know for each year y, how many cells remain.
    // Better approach: process sinking events chronologically by year.
    
    // Reset:
    submerged.assign(H, vector<bool>(W, false));
    vector<queue<pair<int,int>>> events(Y+1); // events[y]: cells that sink at year y
    
    // Initially, border cells sink at year A[i][j] (when sea level reaches their elevation)
    rep(i,H) rep(j,W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            int sink_year = min(A[i][j], Y+1); // cap at Y+1 to avoid overflow
            if (sink_year <= Y) {
                events[sink_year].push({i,j});
            } else if (A[i][j] > Y) {
                // won't sink within Y years
            }
            submerged[i][j] = true;
        }
    }
    
    remaining = H * W;
    // For each year, process all cells that sink at that year
    for (int y = 1; y <= Y; y++) {
        queue<pair<int,int>> q;
        // Add all cells scheduled to sink at year y
        while (!events[y].empty()) {
            auto [i,j] = events[y].front(); 
            events[y].pop();
            if (!q.empty() || !submerged[i][j]) continue; // should be submerged already
            q.push({i,j});
        }
        
        // But we need to propagate from current submerged cells whose elevation <= y
        // Actually, better: maintain a BFS frontier
        
        // Let's do a different approach: maintain a queue of cells that are exposed and adjacent to water
        // But we already started with borders.
        
        // Correction: The original idea was flawed. Let's use multi-source Dijkstra-like approach.
    }
    
    // Final correct approach: Use priority queue to simulate rising sea level
    submerged.assign(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> dijkstra_pq;
    
    // Start with all border cells
    rep(i,H) rep(j,W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            dijkstra_pq.push({A[i][j], {i, j}});
            submerged[i][j] = true;
        }
    }
    
    vector<int> result(Y+1, H*W);
    int count = H*W;
    
    while (!dijkstra_pq.empty()) {
        auto [elev, pos] = dijkstra_pq.top();
        dijkstra_pq.pop();
        
        // This cell becomes submerged when sea level reaches elev
        if (elev < Y) {
            // From year elev onward, this cell is gone
            for (int y = elev; y <= Y; y++) {
                result[y]--;
            }
        } else if (elev <= Y) {
            for (int y = elev; y <= Y; y++) {
                result[y]--;
            }
        }
        count--;
        
        int i = pos.first, j = pos.second;
        rep(k,4) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                submerged[ni][nj] = true;
                dijkstra_pq.push({A[ni][nj], {ni, nj}});
            }
        }
    }
    
    // But again, we are over-decrementing.
    // Correct approach: don't pre-fill result array. Instead, simulate year by year using the fact that
    // a cell sinks at year = its "flooding time", which is the minimum maximum elevation along any path to the border.
    
    // Recompute flooding time for each cell using Dijkstra
    vector<vector<int>> flood_time(H, vector<int>(W, inf));
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq2;
    
    rep(i,H) rep(j,W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            flood_time[i][j] = A[i][j];
            pq2.push({A[i][j], {i, j}});
        }
    }
    
    while (!pq2.empty()) {
        auto [d, pos] = pq2.top(); pq2.pop();
        int i = pos.first, j = pos.second;
        if (d != flood_time[i][j]) continue;
        
        rep(k,4) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                int new_time = max(d, A[ni][nj]);
                if (new_time < flood_time[ni][nj]) {
                    flood_time[ni][nj] = new_time;
                    pq2.push({new_time, {ni, nj}});
                }
            }
        }
    }
    
    // Count how many cells have flood_time > y for each year y
    vector<int> cnt(Y+1, 0);
    rep(i,H) rep(j,W) {
        int t = flood_time[i][j];
        if (t > Y) {
            for (int y = 1; y <= Y; y++) {
                cnt[y]++;
            }
        } else {
            for (int y = 1; y < t; y++) {
                cnt[y]++;
            }
        }
    }
    
    rep(y, Y) {
        cout << cnt[y+1] << '\n';
    }
    
    return 0;
}