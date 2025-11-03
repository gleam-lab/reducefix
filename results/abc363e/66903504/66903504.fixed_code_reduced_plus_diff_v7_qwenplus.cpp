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
    
    // Create events: when each cell gets submerged
    vector<vector<int>> events(Y+1);
    
    // Initialize with border cells
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    queue<pair<int,int>> q;
    
    // Add all border cells to initial queue
    rep(i,H) {
        rep(j,W) {
            if(i == 0 || i == H-1 || j == 0 || j == W-1) {
                submerged[i][j] = true;
                int year = A[i][j];
                if(year <= Y) {
                    events[year].push_back({i, j});
                }
            }
        }
    }
    
    // Process events year by year
    int remaining = H * W;
    
    // We'll use a BFS approach with priority queue to handle the flooding correctly
    // Instead of processing year-by-year events, we use a min-heap to process cells in order of elevation
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    
    // Reset submerged array and add all border cells to priority queue
    fill(submerged.begin(), submerged.end(), vector<bool>(W, false));
    rep(i,H) rep(j,W) {
        if(i == 0 || i == H-1 || j == 0 || j == W-1) {
            pq.push({A[i][j], i, j});
            submerged[i][j] = true;
        }
    }
    
    vector<int> ans(Y+1, H*W);
    int processed = 0;
    
    // Process cells in order of increasing elevation
    while(!pq.empty()) {
        auto [elev, i, j] = pq.top();
        pq.pop();
        
        // This cell gets submerged at year = elev
        if(elev <= Y) {
            ans[elev]--;
        } else {
            // If elevation > Y, it never gets submerged during our observation period
            break;
        }
        
        // Propagate to neighbors
        rep(dir,4) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                submerged[ni][nj] = true;
                pq.push({A[ni][nj], ni, nj});
            }
        }
        
        processed++;
    }
    
    // Fill in the answer array - once a cell is gone, it stays gone
    for(int y = 1; y <= Y; y++) {
        ans[y] = min(ans[y], ans[y-1]);
    }
    
    // Output results for years 1 to Y
    for(int y = 1; y <= Y; y++) {
        cout << ans[y] << '\n';
    }
}