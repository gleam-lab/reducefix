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
    // Instead of processing events per year, collect all border cells and process in increasing order of elevation
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Initialize: all edge cells are adjacent to the sea
    rep(i,H) {
        rep(j,W) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], {i, j}});
                submerged[i][j] = true;
            }
        }
    }
    
    int remaining = H * W;
    vector<int> ans(Y + 1, remaining); // ans[y] = area after y years
    
    while (!pq.empty()) {
        auto [elev, pos] = pq.top(); pq.pop();
        int i = pos.first, j = pos.second;
        
        // This cell gets submerged when sea level reaches elev
        if (elev <= Y) {
            if (ans[elev] == remaining) {
                // First time reaching this elevation
                ans[elev] = --remaining;
            } else {
                ans[elev] = --remaining;
            }
        } else {
            // Even if elev > Y, we still need to process for propagation
            remaining--;
        }
        
        // Propagate to neighbors
        rep(d,4) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                // If neighbor's elevation <= current sea level (which is 'elev'), it will also submerge
                if (A[ni][nj] <= elev) {
                    submerged[ni][nj] = true;
                    pq.push({A[ni][nj], {ni, nj}});
                }
            }
        }
    }
    
    // Fill in the answer array: area at year y is the minimum area from year 1 to y
    // Because once submerged, it stays submerged
    int cur = H * W;
    for (int y = 1; y <= Y; y++) {
        if (y <= Y) {
            // Use previously computed value or carry forward
            if (y < (int)ans.size() && ans[y] < cur) {
                cur = ans[y];
            }
            cout << cur << '\n';
        }
    }
    
    return 0;
}