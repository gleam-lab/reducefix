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
    vector<vector<int>> sink_year(H, vector<int>(W, Y+1));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    
    // Initialize boundary cells
    rep(i,H)rep(j,W){
        if(i==0||i==H-1||j==0||j==W-1){
            sink_year[i][j] = A[i][j];
            pq.push({A[i][j], i, j});
        }
    }
    
    // Dijkstra-like propagation
    while(!pq.empty()){
        auto [year, i, j] = pq.top();
        pq.pop();
        
        if(year != sink_year[i][j]) continue;
        
        rep(k,4){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0&&ni<H&&nj>=0&&nj<W){
                int next_year = max(A[ni][nj], year);
                if(next_year < sink_year[ni][nj]){
                    sink_year[ni][nj] = next_year;
                    pq.push({next_year, ni, nj});
                }
            }
        }
    }
    
    // Count remaining cells for each year
    vector<int> ans(Y+1, H*W);
    vector<int> cnt(Y+2, 0);
    rep(i,H)rep(j,W){
        cnt[sink_year[i][j]]++;
    }
    
    int removed = 0;
    for(int y=1; y<=Y; y++){
        removed += cnt[y];
        ans[y] = H*W - removed;
        cout << ans[y] << '\n';
    }
}