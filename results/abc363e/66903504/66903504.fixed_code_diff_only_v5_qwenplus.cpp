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
    
    // Current sea level after y years is y
    // We want to simulate flooding in increasing order of elevation
    // Instead of processing each year separately, collect all border cells and process by elevation
    
    int total = H * W;
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Add all boundary cells to the priority queue with their elevation
    rep(i,H) rep(j,W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            pq.push({A[i][j], {i, j}});
            submerged[i][j] = true;
        }
    }
    
    vector<int> ans(Y+1, total); // ans[y] = area after y years
    int remaining = total;
    
    // Process cells in increasing order of elevation
    while (!pq.empty()) {
        auto [elev, pos] = pq.top(); pq.pop();
        int i = pos.first, j = pos.second;
        
        // This cell gets submerged when sea level reaches elev
        if (elev < Y) {
            // At year = elev, this cell submerges (if not already counted)
            if (ans[elev] == total) {
                // First time we reach this elevation
                // All previous years should have same value
                for (int y = elev; y <= Y; y++) {
                    if (ans[y] == total) ans[y] = remaining;
                    else break;
                }
            }
        }
        
        // Explore neighbors
        rep(k,4) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                submerged[ni][nj] = true;
                pq.push({A[ni][nj], {ni, nj}});
            }
        }
        
        remaining--;
    }
    
    // Fill in any years that weren't reached
    for (int y = 1; y <= Y; y++) {
        if (ans[y] == total) {
            ans[y] = remaining;
        }
        cout << ans[y] << '\n';
    }
}