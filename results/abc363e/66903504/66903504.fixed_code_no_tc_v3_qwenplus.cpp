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

    // We'll simulate the flooding in reverse: from high sea levels to low
    // Instead, we can process cells by their elevation and use BFS from borders
    // But better approach: process years in increasing order and flood cells with elevation <= current year

    // However, the original idea has bugs:
    // 1. The queue indexing by elevation up to 202020 is wasteful and may not cover all cases
    // 2. Condition in bounds checking is wrong: "ni>=0&&ni<H&&ni>=0&&ni<W" -> should be nj
    // 3. Flooding logic: when sea level is y, any cell with A[i][j] <= y that is connected to the sea should flood
    // 4. We need to propagate flooding correctly from already flooded cells

    // Fix: Use multi-source BFS starting from all border cells.
    // But instead of simulating each year independently, we can precompute when each cell floods.

    // Alternate correct approach:
    // - Start with all border cells as initially exposed to sea
    // - Use priority_queue (min-heap) where priority is the elevation of the cell
    // - At sea level y, all cells with effective flooding level <= y are submerged
    // - The "flooding time" of a cell is max(A[i][j], min_flooding_time_from_neighbor)
    // Actually, we can do Dijkstra-like algorithm: 
    //   Let dist[i][j] = minimum sea level at which (i,j) becomes flooded
    //   For border cells: dist[i][j] = A[i][j]
    //   For inner cells: dist[i][j] = max(A[i][j], min(dist[ni][nj] over neighbors))
    // But note: a cell floods when sea level >= its flooding threshold

    vector<vector<int>> flood_level(H, vector<int>(W, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // Initialize borders
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                flood_level[i][j] = A[i][j];
                pq.push({A[i][j], i, j});
            }
        }
    }

    while (!pq.empty()) {
        auto [lev, i, j] = pq.top(); pq.pop();
        if (lev != flood_level[i][j]) continue;

        rep(k,4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                int new_lev = max(A[ni][nj], lev);
                if (new_lev < flood_level[ni][nj]) {
                    flood_level[ni][nj] = new_lev;
                    pq.push({new_lev, ni, nj});
                }
            }
        }
    }

    // Now, flood_level[i][j] = the sea level at which cell (i,j) gets flooded
    // So at year y, cell (i,j) remains above water iff flood_level[i][j] > y

    vector<int> remaining(Y+1, H*W); // remaining[y] = area after y years
    vector<int> events(Y+2, 0); // events[t] += number of cells that flood at sea level t

    rep(i,H) rep(j,W) {
        int t = flood_level[i][j];
        if (t <= Y) {
            events[t]++;
        } else if (t > Y) {
            // remains above even at year Y
        }
    }

    int cur = H*W;
    for (int y = 1; y <= Y; y++) {
        cur -= events[y];
        cout << cur << '\n';
    }

}