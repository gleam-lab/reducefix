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
    vector<vector<int>> time_to_sink(H, vector<int>(W, Y+1));
    queue<pair<int,int>> q;
    
    // Initialize: border cells will sink at time A[i][j] (if sea level reaches their height)
    rep(i,H)rep(j,W){
        if(i==0||i==H-1||j==0||j==W-1){
            time_to_sink[i][j] = A[i][j];
            q.push({i,j});
        }
    }
    
    // BFS to propagate sinking times
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        int t = time_to_sink[i][j];
        
        rep(k,4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni>=0 && ni<H && nj>=0 && nj<W){
                // The neighbor will sink when max(A[ni][nj], current_sinking_time)
                // But it can't sink earlier than its own height
                int new_time = max(A[ni][nj], t);
                if(new_time < time_to_sink[ni][nj]){
                    time_to_sink[ni][nj] = new_time;
                    q.push({ni,nj});
                }
            }
        }
    }
    
    // Count remaining area for each year
    vector<int> remaining(Y+1, H*W);
    rep(i,H)rep(j,W){
        if(time_to_sink[i][j] <= Y){
            remaining[time_to_sink[i][j]]--;
        }
    }
    
    // Convert to cumulative counts
    for(int y=1; y<=Y; y++){
        remaining[y] += remaining[y-1];
    }
    
    for(int y=1; y<=Y; y++){
        cout << remaining[y] << '\n';
    }
}