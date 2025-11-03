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
    
    // Current area of the island above sea level
    int ans = H*W;
    // F[i][j] = true means the cell is still above water
    vector<vector<bool>> F(H, vector<bool>(W, true));
    
    // We'll use a single queue and process rising sea levels year by year
    queue<pair<int,int>> q;
    
    // Initially, mark all border cells that are submerged at their elevation or below
    // But instead, we will add all border cells to be processed when sea level reaches A[i][j]
    // Instead, let's use events: for each sea level, which cells get submerged?
    // Since Y can be up to 1e5 and A[i][j] up to 1e5, we can have array of vectors
    
    vector<vector<pair<int,int>>> events(100100); // events[t] = list of (i,j) that are on border and with A[i][j] <= t
    
    // But better: precompute for each cell on border, add it to event at time A[i][j]
    rep(i,H)rep(j,W){
        if(i==0 || i==H-1 || j==0 || j==W-1){
            events[A[i][j]].push_back({i,j});
        }
    }
    
    // Now simulate year y from 1 to Y
    for(int y=1; y<=Y; y++){
        // Add all border cells that have elevation <= y and haven't been processed
        for(auto [i,j] : events[y]){
            if(F[i][j]){
                F[i][j] = false;
                q.push({i,j});
                ans--;
            }
        }
        
        // Flood fill from all currently submerged cells
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            rep(k,4){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W){
                    if(F[ni][nj] && A[ni][nj] <= y){
                        F[ni][nj] = false;
                        q.push({ni,nj});
                        ans--;
                    }
                }
            }
        }
        
        cout << ans << '\n';
    }
}