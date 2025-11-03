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
    queue<tuple<int,int,int>> q; // (year, i, j)
    
    // Initialize: border cells will be submerged at year A[i][j]
    rep(i,H)rep(j,W){
        if(i==0||i==H-1||j==0||j==W-1){
            submerge_year[i][j] = A[i][j];
            q.push({A[i][j], i, j});
        }
    }
    
    // BFS to propagate submersion
    while(!q.empty()){
        auto [year, i, j] = q.front(); q.pop();
        if(submerge_year[i][j] != year) continue; // outdated
        
        rep(k,4){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0&&ni<H&&nj>=0&&nj<W){
                int next_year = max(year, A[ni][nj]);
                if(next_year < submerge_year[ni][nj]){
                    submerge_year[ni][nj] = next_year;
                    q.push({next_year, ni, nj});
                }
            }
        }
    }
    
    // Count how many cells remain above water at each year
    vector<int> count(Y+2, H*W); // count[y] = area at year y
    rep(i,H)rep(j,W){
        if(submerge_year[i][j] <= Y){
            count[submerge_year[i][j]]--;
        }
    }
    
    // Convert to prefix sum (decreasing)
    for(int y=1; y<=Y; y++){
        count[y] += count[y-1];
        cout << count[y] << '\n';
    }
}