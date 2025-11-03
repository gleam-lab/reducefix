#include<bits/stdc++.h>
using namespace std;
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
    
    // Initialize answer and visited array
    int ans = H*W;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Group cells by their elevation for processing in increasing order
    vector<vector<pair<int,int>>> cellsAtElevation(100001); // A_{i,j} up to 10^5
    
    // Add border cells to be processed first since they are exposed to the sea
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                cellsAtElevation[A[i][j]].push_back({i, j});
                visited[i][j] = true;
                ans--;
            }
        }
    }
    
    // We'll simulate year-by-year, but use BFS-like propagation with priority on elevation
    // Instead of storing queues per year, we process all cells that get submerged at or before current sea level
    
    // But we cannot pre-submerge everything. We need to simulate each year.
    // However, we can do: for each year y, process all cells with elevation <= y that are connected to the sea via already submerged cells.
    
    // Better idea: Use multi-source BFS starting from borders, ordered by max(elevation, time)
    // But simpler: Process events by elevation, and maintain a min-heap (priority queue) of boundary cells.
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    // (elevation, i, j)
    
    // Reset visited and reinitialize pq with border cells
    rep(i,H)rep(j,W)visited[i][j]=false;
    
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }
    
    // We will answer each year incrementally
    // Each time the sea level rises, more cells may be submerged
    // But note: a cell is submerged when sea level >= its elevation AND it's connected to the sea
    
    // The key: use Dijkstra-like approach where "time" to submerge a cell is max(A[i][j], earliest neighbor submersion time)
    // Actually: a cell gets submerged at year = max(A[i][j], min_year_from_any_neighbor_path_from_border)
    // But actually: it's the minimum over paths of the maximum elevation along the path? No.
    
    // Correct idea: A cell gets submerged at year = the minimum value T such that there exists a path from border 
    // to this cell where every cell on the path has elevation <= T.
    // This is equivalent to: T must be at least the maximum elevation along some path from border.
    // So the earliest year when (i,j) is submerged is the minimum over all border-to-(i,j) paths of the maximum elevation on the path.
    
    // That is the standard "minimum maximum edge weight" path — solved by modified Dijkstra.
    
    vector<vector<int>> submergenceYear(H, vector<int>(W, inf));
    
    while (!pq.empty()) {
        auto [elev, i, j] = pq.top(); pq.pop();
        if (submergenceYear[i][j] != inf) continue;
        submergenceYear[i][j] = elev;
        
        rep(k,4) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && submergenceYear[ni][nj] == inf) {
                int newElev = max(elev, A[ni][nj]);
                pq.push({newElev, ni, nj});
            }
        }
    }
    
    // Now, for each year y from 1 to Y, count how many cells have submergenceYear > y
    vector<int> remaining(Y+1, H*W);
    rep(i,H) rep(j,W) {
        int t = submergenceYear[i][j];
        if (t <= Y) {
            for (int y = t; y <= Y; y++) {
                remaining[y]--;
            }
        }
    }
    
    rep(y, Y) {
        cout << remaining[y+1] << '\n';
    }

}