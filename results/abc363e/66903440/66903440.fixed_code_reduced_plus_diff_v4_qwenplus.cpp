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
    
    // Create events: when each cell gets flooded
    vector<vector<int>> flood_time(H, vector<int>(W, Y+1));
    queue<pair<int,int>> q;
    
    // Initialize: border cells will be flooded at time A[i][j]
    rep(i,H){
        rep(j,W){
            if(i == 0 || i == H-1 || j == 0 || j == W-1){
                flood_time[i][j] = A[i][j];
                q.push({i,j});
            }
        }
    }
    
    // BFS to determine when each cell gets flooded
    // A cell gets flooded at max(A[i][j], min_flood_time_of_neighbors)
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        int current_time = flood_time[i][j];
        
        rep(k,4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < H && nj >= 0 && nj < W){
                int next_time = max(A[ni][nj], current_time);
                if(flood_time[ni][nj] > next_time){
                    flood_time[ni][nj] = next_time;
                    q.push({ni,nj});
                }
            }
        }
    }
    
    // Count cells that survive after y years
    vector<int> ans(Y+1, H*W);
    vector<int> cnt(Y+2, 0); // cnt[t] = number of cells flooded at time t
    
    rep(i,H)rep(j,W){
        cnt[flood_time[i][j]]++;
    }
    
    int remaining = H*W;
    for(int y = 1; y <= Y; y++){
        remaining -= cnt[y];
        cout << remaining << '\n';
    }
}