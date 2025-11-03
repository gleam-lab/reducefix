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
    
    // Current area of the island above water
    int ans = H*W;
    // F[i][j] = true means cell (i,j) is still above water
    vector<vector<bool>> F(H, vector<bool>(W, true));
    
    // We'll use events: for each sea level y, store cells that get submerged when sea level reaches y
    // Instead of storing queues for all possible A[i][j], we can process year by year with a priority queue
    // But simpler: precompute for each boundary cell and propagate using BFS per year? -> too slow
    
    // Better idea: simulate rising sea level from 1 to Y
    // At year y, sea level = y. Any land with elevation <= y that is connected to the sea will be submerged.
    // However, once submerged, it stays submerged.
    
    // We can instead start from the boundaries and simulate flooding in increasing order of elevation.
    // Use a min-heap (priority queue) to process cells in order of when they get flooded.
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    // tuple: (elevation_threshold, i, j)
    // elevation_threshold = max(A[i][j], initial_sea_level_when_flooded_from_boundary)
    
    // Initially, all boundary cells are exposed to sea
    rep(i,H)rep(j,W){
        if(i==0 || i==H-1 || j==0 || j==W-1){
            F[i][j] = false;
            pq.push({A[i][j], i, j});
        }
    }
    
    // For each year, we want to output the remaining area
    vector<int> result;
    
    for(int y = 1; y <= Y; y++){
        // Process all cells that get flooded at sea level <= y
        while(!pq.empty()){
            auto [lev, i, j] = pq.top();
            if(lev > y) break; // This cell won't flood until later
            pq.pop();
            
            // This cell gets flooded at level <= y
            if(!F[i][j]) continue; // Already processed
            
            F[i][j] = false;
            ans--;
            
            // Check neighbors
            rep(k,4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && F[ni][nj]){
                    // The neighbor will be flooded when sea level reaches at least A[ni][nj]
                    // But also, since this cell is now flooded, the effective threshold is max(A[ni][nj], current_path_threshold)
                    // However, note: the flooding happens when sea level >= A[ni][nj] AND connected to sea
                    // So we can push with threshold = A[ni][nj] because connection is already ensured via this path
                    pq.push({A[ni][nj], ni, nj});
                }
            }
        }
        result.push_back(ans);
    }
    
    for(int x : result) cout << x << '\n';
}