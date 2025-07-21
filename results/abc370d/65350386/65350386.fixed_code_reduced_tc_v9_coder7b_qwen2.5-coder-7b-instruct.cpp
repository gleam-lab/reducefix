#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int h,w,q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h,vector<bool>(w,true));
    while(q--){
        int r,c;
        cin >> r >> c;
        r--;c--;
        if(grid[r][c]){
            grid[r][c]=false;
            continue;
        }
        for(int i=0;i<h;i++){
            if(!grid[i][c]||i==r)continue;
            grid[i][c]=false;
        }
        for(int i=0;i<w;i++){
            if(!grid[r][i]||i==c)continue;
            grid[r][i]=false;
        }
    }
    int ans=0;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(grid[i][j])ans++;
    cout<<ans<<"\n";
    return 0;
}