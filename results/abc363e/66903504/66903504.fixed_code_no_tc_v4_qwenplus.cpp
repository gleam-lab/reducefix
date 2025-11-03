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

    // Store cells by their elevation
    vector<vector<pair<int,int>>> cells_at_elevation(100001);
    rep(i,H)rep(j,W){
        cells_at_elevation[A[i][j]].pb({i,j});
    }

    int ans = H*W;
    vector<vector<bool>> submerged(H, vector<bool>(W, false));
    
    // Process each year from 1 to Y
    for(int y = 1; y <= Y; y++){
        // Add all cells with elevation <= y that haven't been processed yet
        for(auto [i,j] : cells_at_elevation[y]){
            if(!submerged[i][j]){
                submerged[i][j] = true;
                ans--;
            }
        }
        
        // Use BFS to propagate submersion from newly submerged border-adjacent cells
        // But we need to do multi-source BFS over all newly submerged cells that are connected to the sea
        // Instead, we use a queue and process propagation only once per year
        
        queue<pair<int,int>> q;
        // Reinitialize: find all currently submerged cells on the border and add them to queue
        // Actually, better approach: maintain a queue of active submerged cells that can spread
        // But simpler: each year, do BFS from all border cells that are submerged and can spread
        
        // Instead: maintain a global queue of "active" submerged cells that can erode neighbors
        // We'll rework: maintain a queue that persists across years
    }
}