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
    
    // We'll simulate from sea level 1 to Y
    // Instead of processing each year separately with queues per elevation,
    // we use a priority queue (min-heap) to process cells in order of when they get submerged.
    
    // Min-heap: {elevation, row, col}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    // Initially, all border cells will be submerged at time = A[i][j] (since sea level rises 1 per year)
    // But note: if a border cell has elevation <= current sea level, it gets submerged
    // So we add all border cells to the priority queue with their elevation as the submersion time
    rep(i,H) rep(j,W) {
        if(i == 0 || i == H-1 || j == 0 || j == W-1) {
            pq.push({A[i][j], i, j});
            submerged[i][j] = true;
            remaining--;
        }
    }
    
    // We'll store answers for each year
    vector<int> ans(Y+1, remaining); // ans[y] = area after y years
    
    // Process cells in order of increasing submersion time
    while(!pq.empty()) {
        auto [elev, i, j] = pq.top();
        pq.pop();
        
        // This cell was scheduled to be submerged at 'elev' years
        // But it might have been already counted in an earlier year
        // Actually, since we use min-heap and mark on insertion, this should be consistent
        
        // Update all years from current elevation onward
        while(ans.size() > elev && ans[elev] == H*W) {
            ans[elev] = remaining;
        }
        
        // Check neighbors
        rep(k,4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                // The neighbor gets submerged when sea level reaches max(A[ni][nj], elev)?
                // No: actually, once this cell is submerged, if sea level is already high enough,
                // the neighbor can be submerged too. But the neighbor will be submerged when
                // sea level reaches A[ni][nj], but it can only be reached through a submerged path.
                // We use Dijkstra-like approach: the "time" when a cell becomes reachable is
                // max(A[ni][nj], time_when_neighbor_was_submerged)
                
                // Actually, correct logic: a cell gets submerged when sea level >= its elevation
                // AND it is connected to the sea via already submerged cells.
                // We simulate using: the effective submersion time of a cell is max(A[cell], min_submersion_time_of_neighbors)
                // But standard approach is to use: push with time = max(A[ni][nj], elev)
                // However, that's not quite right either.
                
                // Let's rethink: 
                // A cell gets submerged when sea level >= its elevation AND it is adjacent to a submerged cell.
                // So we do:
                //   When processing a cell submerged at time t, we look at neighbors.
                //   If neighbor has elevation <= current sea level (which is t), then it should also be submerged now.
                // But wait: sea level at year t is exactly t.
                // So if A[ni][nj] <= t, then it gets submerged at time t.
                // Otherwise, it remains until sea level reaches A[ni][nj].
                //
                // But the problem says: when a section newly sinks, any adjacent section with elevation <= sea level also sinks.
                // And this propagates.
                //
                // So we need to propagate: if a cell is submerged at time t, and its neighbor has A[ni][nj] <= t,
                // then that neighbor should be submerged at time t.
                // If A[ni][nj] > t, then it won't be submerged yet, but when sea level reaches A[ni][nj],
                // it might be disconnected? No, because the connection exists.
                //
                // Actually, the key insight: a cell is submerged at time = min over all paths to border of max(along path))
                // This is a classic "minimum maximum edge along path" or "bottleneck shortest path".
                // So we use Dijkstra variant: dist[i][j] = minimum value of maximum elevation along any path from border to (i,j)
                // Then cell (i,j) is submerged at time = dist[i][j]
                //
                // But note: the cell is submerged when sea level reaches the bottleneck value.
                //
                // So algorithm:
                //   dist[i][j] = minimum over all paths from border to (i,j) of max(edge values along path)
                //   where edge value is the elevation of the cell.
                //   Then at year y, cell (i,j) is submerged iff dist[i][j] <= y
                //
                // How to compute dist?
                //   Use priority queue: start with all border cells, dist[i][j] = A[i][j]
                //   Then relax: for neighbor (ni,nj), new_dist = max(dist[i][j], A[ni][nj])
                //   If new_dist < dist[ni][nj], update.
                //
                // Then we can count for each year y, number of cells with dist[i][j] > y
            }
        }
    }
    
    // Let's implement the Dijkstra-style bottleneck approach
    vector<vector<int>> dist(H, vector<int>(W, inf));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq2;
    
    // Initialize border cells
    rep(i,H) rep(j,W) {
        if(i == 0 || i == H-1 || j == 0 || j == W-1) {
            dist[i][j] = A[i][j];
            pq2.push({A[i][j], i, j});
        }
    }
    
    while(!pq2.empty()) {
        auto [d, i, j] = pq2.top();
        pq2.pop();
        if(d != dist[i][j]) continue;
        
        rep(k,4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W) {
                int new_dist = max(d, A[ni][nj]);
                if(new_dist < dist[ni][nj]) {
                    dist[ni][nj] = new_dist;
                    pq2.push({new_dist, ni, nj});
                }
            }
        }
    }
    
    // Now, for each year y from 1 to Y, count cells where dist[i][j] > y
    vector<int> count(Y+1, 0); // count[y] = number of cells submerged at time <= y
    rep(i,H) rep(j,W) {
        if(dist[i][j] <= Y) {
            count[dist[i][j]]++;
        }
    }
    
    int submerged_count = 0;
    rep(y, Y) {
        if(y+1 <= Y) {
            submerged_count += count[y+1];
        }
        cout << (H*W - submerged_count) << endl;
    }
    
    return 0;
}