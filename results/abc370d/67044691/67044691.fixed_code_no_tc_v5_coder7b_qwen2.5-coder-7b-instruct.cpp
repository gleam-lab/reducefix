#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
    ll h,w,q;cin >> h >> w >> q;
    vector<vb> grid(h,vector<vb>(w,true));
    
    rep(i,q){
        ll r,c;cin >> r >> c;
        r--;c--;
        
        if(grid[r][c]){
            grid[r][c] = false;
        }else{
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr==0&&dc==0) continue;
                    int nr=r+dr,nc=c+dc;
                    while(nr>=0&&nr<h&&nc>=0&&nc<w&&!grid[nr][nc]){
                        grid[nr][nc] = true;
                        nr+=dr;
                        nc+=dc;
                    }
                }
            }
        }
    }
    
    ll ans=0;
    rep(i,h){
        rep(j,w){
            if(grid[i][j]) ans++;
        }
    }
    cout << ans << endl;
}