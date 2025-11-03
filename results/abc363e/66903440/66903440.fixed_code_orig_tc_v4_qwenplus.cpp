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
    
    // Create events: when each cell sinks
    vector<vector<int>> sink_year(H, vector<int>(W, Y+1));
    queue<pair<int,int>> q;
    
    // Initialize: all border cells will eventually sink
    rep(i,H){
        rep(j,W){
            if(i==0||i==H-1||j==0||j==W-1){
                sink_year[i][j] = A[i][j];
                q.push({i,j});
            }
        }
    }
    
    // BFS to determine when each cell sinks
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        int current_sink = sink_year[i][j];
        
        rep(k,4){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0 && ni<H && nj>=0 && nj<W){
                // The neighbor can only sink when sea level reaches max(A[ni][nj], current_sink)
                int required_level = max(A[ni][nj], current_sink);
                if(required_level < sink_year[ni][nj]){
                    sink_year[ni][nj] = required_level;
                    q.push({ni,nj});
                }
            }
        }
    }
    
    // Count how many cells remain above water for each year
    vector<int> count(Y+1, H*W);
    vector<int> sink_events(Y+2, 0); // sink_events[t] = number of cells that sink at year t
    
    rep(i,H)rep(j,W){
        int t = min(sink_year[i][j], Y+1);
        if(t <= Y){
            sink_events[t]++;
        }
    }
    
    // Calculate remaining area for each year
    for(int y=1; y<=Y; y++){
        count[y] = count[y-1] - sink_events[y];
        cout << count[y] << '\n';
    }
}