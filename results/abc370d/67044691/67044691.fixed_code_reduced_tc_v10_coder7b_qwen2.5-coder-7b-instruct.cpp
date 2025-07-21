#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repi(i,a,b) for(int i=a;i<b;i++)
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
    vector<vb> grid(h,vector<bool>(w,true));
    rep(i,q){
        ll r,c;cin >> r >> c;
        r--;c--;
        if(grid[r][c]){
            grid[r][c] = false;
        }else{
            repi(j,0,w){
                if(grid[r][j]) {
                    grid[r][j] = false;
                    break;
                }
            }
            repi(j,w-1,-1){
                if(grid[r][j]) {
                    grid[r][j] = false;
                    break;
                }
            }
            repi(j,0,h){
                if(grid[j][c]) {
                    grid[j][c] = false;
                    break;
                }
            }
            repi(j,h-1,-1){
                if(grid[j][c]) {
                    grid[j][c] = false;
                    break;
                }
            }
        }
    }
    ll ans=0;
    rep(i,h){
        rep(j,w){
            if(grid[i][j])ans++;
        }
    }
    cout << ans << endl;
}