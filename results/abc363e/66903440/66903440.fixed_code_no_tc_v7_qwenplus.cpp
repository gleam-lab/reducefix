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
    
    // We'll simulate the flooding in reverse order using union-find or simply process by elevation
    // Instead of simulating year-by-year with BFS from coast, we can use offline queries.
    // Idea: Process cells in increasing order of elevation and simulate flooding over time.
    
    // Collect all boundary cells and sort by elevation
    vector<tuple<int,int,int>> events; // (elevation, i, j)
    
    rep(i,H) rep(j,W) {
        if(i == 0 || i == H-1 || j == 0 || j == W-1) {
            events.push_back({A[i][j], i, j});
        }
    }
    
    sort(all(events));
    
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    int remaining = H * W;
    
    // For each year, we want to output remaining area
    vector<int> ans(Y+1, remaining); // ans[y] = area after y years
    
    int idx = 0;
    queue<pair<int,int>> q;
    
    for(int y = 1; y <= Y; y++) {
        // All boundary cells with A[i][j] <= y will start flooding
        while(idx < (int)events.size() && get<0>(events[idx]) <= y) {
            auto [elev, i, j] = events[idx];
            idx++;
            if(!submerged[i][j]) {
                submerged[i][j] = true;
                remaining--;
                q.push({i,j});
            }
        }
        
        // Propagate flooding from all currently flooded cells
        // But we need to avoid reprocessing, so we do BFS for this year's propagation
        queue<pair<int,int>> temp_q;
        while(!q.empty()) {
            temp_q.push(q.front());
            q.pop();
        }
        
        while(!temp_q.empty()) {
            auto [i,j] = temp_q.front();
            temp_q.pop();
            
            rep(k,4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && !submerged[ni][nj]) {
                    // If neighbor hasn't sunk and its elevation <= current sea level (y)
                    if(A[ni][nj] <= y) {
                        submerged[ni][nj] = true;
                        remaining--;
                        q.push({ni,nj}); // add to global q for next steps
                        temp_q.push({ni,nj}); // continue propagation
                    }
                }
            }
        }
        
        ans[y] = remaining;
    }
    
    for(int y = 1; y <= Y; y++) {
        cout << ans[y] << endl;
    }
    
    return 0;
}