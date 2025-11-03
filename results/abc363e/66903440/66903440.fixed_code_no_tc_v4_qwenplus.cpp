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
    
    // We'll process cells in increasing order of elevation
    // Instead of simulating year-by-year with queues per elevation,
    // we can use a priority queue or sort all border cells by elevation
    
    // Alternative efficient approach:
    // 1. Start from the perimeter (connected to sea initially)
    // 2. Use a min-heap (priority queue) to simulate flooding in order of elevation
    // 3. For each sea level rise, flood all cells <= current sea level that are connected to the sea
    
    int total = H * W;
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize: all boundary cells are adjacent to sea
    rep(i,H) {
        if (!submerged[i][0]) {
            submerged[i][0] = true;
            pq.push({A[i][0], {i, 0}});
        }
        if (W > 1 && !submerged[i][W-1]) {
            submerged[i][W-1] = true;
            pq.push({A[i][W-1], {i, W-1}});
        }
    }
    rep(j,W) {
        if (!submerged[0][j]) {
            submerged[0][j] = true;
            pq.push({A[0][j], {0, j}});
        }
        if (H > 1 && !submerged[H-1][j]) {
            submerged[H-1][j] = true;
            pq.push({A[H-1][j], {H-1, j}});
        }
    }
    
    // Store results for each year
    vector<int> result(Y+1);
    int submerged_count = 0;
    
    // Process each year from 1 to Y
    for (int year = 1; year <= Y; year++) {
        // Flood all cells with elevation <= year that are reachable
        while (!pq.empty() && pq.top().first <= year) {
            auto [elev, pos] = pq.top();
            pq.pop();
            int i = pos.first, j = pos.second;
            
            // This cell gets flooded at this elevation
            submerged_count++;
            
            // Check neighbors
            rep(d,4) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                    submerged[ni][nj] = true;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
        result[year] = total - submerged_count;
    }
    
    // Output results for each year
    for (int i = 1; i <= Y; i++) {
        cout << result[i] << '\n';
    }
}