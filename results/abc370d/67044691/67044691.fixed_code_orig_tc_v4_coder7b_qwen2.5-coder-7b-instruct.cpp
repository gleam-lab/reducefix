#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
    ll h,w,q;cin >> h >> w >> q;
    vector<vector<pair<int,int>>> adj(h,vector<pair<int,int>>(w));
    rep(i,h)rep(j,w){
        adj[i][j]={i,j};
    }
    
    while(q--){
        ll r,c;cin >> r >> c;
        --r,--c;
        auto [x,y] = adj[r][c];
        adj[x][y]={-1,-1}; // mark as visited
        
        // update neighbors
        if(y > 0){
            auto [nx,ny] = adj[x][y-1];
            while(nx != -1){
                swap(adj[nx][ny],adj[x][y]);
                tie(nx,ny)=adj[nx][ny];
            }
        }
        if(y < w-1){
            auto [nx,ny] = adj[x][y+1];
            while(nx != -1){
                swap(adj[nx][ny],adj[x][y]);
                tie(nx,ny)=adj[nx][ny];
            }
        }
        if(x > 0){
            auto [nx,ny] = adj[x-1][y];
            while(nx != -1){
                swap(adj[nx][ny],adj[x][y]);
                tie(nx,ny)=adj[nx][ny];
            }
        }
        if(x < h-1){
            auto [nx,ny] = adj[x+1][y];
            while(nx != -1){
                swap(adj[nx][ny],adj[x][y]);
                tie(nx,ny)=adj[nx][ny];
            }
        }
    }
    
    ll ans=0;
    rep(i,h)rep(j,w){
        if(adj[i][j] == make_pair(-1,-1)) continue;
        ++ans;
    }
    cout << ans << '\n';
}