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
    while(q--){
        ll r,c;cin >> r >> c;
        r--;c--;
        if(grid[r][c]){
            grid[r][c] = false;
            // Check upwards
            for(ll i=r-1; i>=0; --i){
                if(grid[i][c]) {
                    grid[i][c] = false;
                } else break;
            }
            // Check downwards
            for(ll i=r+1; i<h; ++i){
                if(grid[i][c]) {
                    grid[i][c] = false;
                } else break;
            }
            // Check leftwards
            for(ll j=c-1; j>=0; --j){
                if(grid[r][j]) {
                    grid[r][j] = false;
                } else break;
            }
            // Check rightwards
            for(ll j=c+1; j<w; ++j){
                if(grid[r][j]) {
                    grid[r][j] = false;
                } else break;
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