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
    queue<tuple<int,int,int>> q; // (year, i, j)
    
    // Initialize: all border cells will sink at year = A[i][j]
    rep(i,H){
        rep(j,W){
            if(i==0 || i==H-1 || j==0 || j==W-1){
                int year = A[i][j];
                sink_year[i][j] = year;
                q.push({year, i, j});
            }
        }
    }
    
    // BFS to propagate sinking
    while(!q.empty()){
        auto [year, i, j] = q.front(); q.pop();
        if(year != sink_year[i][j]) continue; // outdated
        
        rep(k,4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni>=0 && ni<H && nj>=0 && nj<W){
                // The neighbor will sink at max(A[ni][nj], current_sink_year)
                // But only if it hasn't been processed with an earlier year
                int next_year = max(A[ni][nj], year);
                if(next_year < sink_year[ni][nj]){
                    sink_year[ni][nj] = next_year;
                    q.push({next_year, ni, nj});
                }
            }
        }
    }
    
    // Count remaining cells for each year
    vector<int> remaining(Y+1, H*W);
    vector<int> changes(Y+2, 0); // changes[i] = number of cells that sink at year i
    
    rep(i,H)rep(j,W){
        if(sink_year[i][j] <= Y){
            changes[sink_year[i][j]]++;
        }
    }
    
    for(int y=1; y<=Y; y++){
        remaining[y] = remaining[y-1] - changes[y];
        cout << remaining[y] << '\n';
    }
}