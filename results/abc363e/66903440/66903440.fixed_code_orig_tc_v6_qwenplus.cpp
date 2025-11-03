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
    queue<tuple<int,int,int>> q; // (time, i, j)
    
    // Initialize: border cells get flooded at time A[i][j] (if <= Y)
    rep(i,H)rep(j,W){
        if(i==0||i==H-1||j==0||j==W-1){
            int t = A[i][j];
            if(t <= Y){
                flood_time[i][j] = t;
                q.push({t, i, j});
            }
        }
    }
    
    // BFS to propagate flooding
    while(!q.empty()){
        auto [t, i, j] = q.front(); q.pop();
        if(flood_time[i][j] != t) continue; // outdated
        
        rep(k,4){
            int ni = i + dx[k], nj = j + dy[k];
            if(ni>=0 && ni<H && nj>=0 && nj<W){
                int nt = max(t, A[ni][nj]);
                if(nt <= Y && nt < flood_time[ni][nj]){
                    flood_time[ni][nj] = nt;
                    q.push({nt, ni, nj});
                }
            }
        }
    }
    
    // Count remaining area for each year
    vector<int> ans(Y+1, H*W);
    vector<int> diff(Y+2, 0);
    
    rep(i,H)rep(j,W){
        if(flood_time[i][j] <= Y){
            diff[flood_time[i][j]]--;
        }
    }
    
    for(int y=1; y<=Y; y++){
        ans[y] = ans[y-1] + diff[y];
        cout << ans[y] << '\n';
    }
}