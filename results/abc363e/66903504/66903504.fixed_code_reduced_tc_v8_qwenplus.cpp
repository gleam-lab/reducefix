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
    queue<pair<int,int>> q;
    
    // Initially, border cells will submerge at year A[i][j] (or earlier)
    rep(i,H)rep(j,W){
        if(i==0 || i==H-1 || j==0 || j==W-1){
            submerge_year[i][j] = A[i][j];
            q.push({i,j});
        }
    }
    
    // BFS to propagate submersion
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        int current_year = submerge_year[i][j];
        
        rep(k,4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni>=0 && ni<H && nj>=0 && nj<W){
                // The neighbor will submerge at max(current_year, A[ni][nj])
                // But only if this is earlier than its current submersion year
                int new_year = max(current_year, A[ni][nj]);
                if(new_year < submerge_year[ni][nj]){
                    submerge_year[ni][nj] = new_year;
                    q.push({ni,nj});
                }
            }
        }
    }
    
    // Count how many cells remain above water at each year
    vector<int> remaining(Y+1, H*W);
    vector<int> events(Y+2, 0); // events[y] = number of cells that submerge at year y
    
    rep(i,H)rep(j,W){
        int year = submerge_year[i][j];
        if(year <= Y){
            events[year]++;
        }
    }
    
    int submerged = 0;
    for(int y=1; y<=Y; y++){
        submerged += events[y];
        cout << (H*W - submerged) << '\n';
    }
}