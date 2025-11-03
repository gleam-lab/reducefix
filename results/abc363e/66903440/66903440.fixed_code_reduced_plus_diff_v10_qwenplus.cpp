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
    vector<vector<int>> submerge_year(H, vector<int>(W, Y+1));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    
    // Initialize: border cells will be submerged at year = A[i][j]
    rep(i,H){
        rep(j,W){
            if(i==0 || i==H-1 || j==0 || j==W-1){
                submerge_year[i][j] = A[i][j];
                pq.push({A[i][j], i, j});
            }
        }
    }
    
    // Dijkstra-like BFS to propagate submergence
    while(!pq.empty()){
        auto [year, i, j] = pq.top();
        pq.pop();
        
        if(submerge_year[i][j] != year) continue;
        
        rep(k,4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W){
                // The new cell will be submerged at max(current sea level, its elevation)
                // But it can't happen earlier than the current propagation
                int new_year = max(year, A[ni][nj]);
                if(new_year < submerge_year[ni][nj]){
                    submerge_year[ni][nj] = new_year;
                    pq.push({new_year, ni, nj});
                }
            }
        }
    }
    
    // Count remaining cells for each year
    vector<int> remaining(Y+1, H*W);
    vector<int> events(Y+2, 0); // events[y] = number of cells submerged at year y
    
    rep(i,H)rep(j,W){
        int y = submerge_year[i][j];
        if(y <= Y){
            events[y]++;
        }
    }
    
    // Calculate remaining area for each year
    for(int y = 1; y <= Y; y++){
        remaining[y] = remaining[y-1] - events[y];
        cout << remaining[y] << '\n';
    }
}