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
    cin.tie(nullptr);

    int H,W,Y;
    cin>>H>>W>>Y;
    vector<vector<int>>A(H,vector<int>(W));
    rep(i,H)rep(j,W)cin>>A[i][j];
    
    // Create events: when each cell gets flooded
    vector<vector<int>> flood_year(H, vector<int>(W, Y+1));
    queue<pair<int,int>> q;
    
    // Initialize: all border cells will be flooded at year A[i][j] or earlier
    rep(i,H)rep(j,W){
        if(i==0||i==H-1||j==0||j==W-1){
            flood_year[i][j] = A[i][j];
            q.push({i,j});
        }
    }
    
    // BFS to propagate flooding
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        int current_year = flood_year[i][j];
        
        rep(k,4){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0 && ni<H && nj>=0 && nj<W){
                // The neighbor will be flooded when sea level reaches max(A[ni][nj], current_year)
                int new_year = max(A[ni][nj], current_year);
                if(new_year < flood_year[ni][nj]){
                    flood_year[ni][nj] = new_year;
                    q.push({ni,nj});
                }
            }
        }
    }
    
    // Count remaining area for each year
    vector<int> ans(Y+1, H*W);
    vector<int> events(Y+2, 0); // events[y] = number of cells flooded at year y
    
    rep(i,H)rep(j,W){
        int year = min(flood_year[i][j], Y);
        events[year]++;
    }
    
    int remaining = H*W;
    for(int y=1; y<=Y; y++){
        remaining -= events[y];
        cout << remaining << '\n';
    }
}