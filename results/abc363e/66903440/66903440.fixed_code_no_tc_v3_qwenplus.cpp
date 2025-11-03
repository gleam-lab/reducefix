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
    // Visited array to track sunk cells
    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    
    // We'll process sinking in increasing order of elevation
    // Group cells by their elevation
    vector<vector<pair<int,int>>> cells_at_elevation(100001);
    
    // Add border cells to be processed first since they are adjacent to sea
    rep(i,H) {
        cells_at_elevation[A[i][0]].push_back({i, 0});
        cells_at_elevation[A[i][W-1]].push_back({i, W-1});
    }
    rep(j,1,W-1) {
        cells_at_elevation[A[0][j]].push_back({0, j});
        if (H > 1) {
            cells_at_elevation[A[H-1][j]].push_back({H-1, j});
        }
    }
    
    // Mark and sink cells for each sea level from 1 to Y
    queue<pair<int,int>> q;
    
    for (int year = 1; year <= Y; year++) {
        // Add all cells with elevation == year on the border (or connected via sinking)
        for (auto [i, j] : cells_at_elevation[year]) {
            if (!sunk[i][j]) {
                sunk[i][j] = true;
                q.push({i, j});
                ans--;
            }
        }
        
        // Flood fill: propagate sinking to adjacent cells with elevation <= current sea level
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            
            rep(k,4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj] && A[ni][nj] <= year) {
                    sunk[ni][nj] = true;
                    q.push({ni, nj});
                    ans--;
                }
            }
        }
        
        cout << ans << '\n';
    }
}