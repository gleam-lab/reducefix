#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

const int mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h,w,q;
    cin>>h>>w>>q;

    vector<vi> grid(h+1,vi(w+1,1));
    
    rep(i,0,q){
        int r,c;
        cin>>r>>c;
        if(grid[r][c]==0){
            continue;
        }
        grid[r][c]=0;
        if(r-1>=1 && grid[r-1][c]==1){grid[r-1][c]=0;}
        if(r+1<=h && grid[r+1][c]==1){grid[r+1][c]=0;}
        if(c-1>=1 && grid[r][c-1]==1){grid[r][c-1]=0;}
        if(c+1<=w && grid[r][c+1]==1){grid[r][c+1]=0;}
    }

    ll ans=0;
    rep(i,1,h+1){
        rep(j,1,w+1){
            if(grid[i][j]==1){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}