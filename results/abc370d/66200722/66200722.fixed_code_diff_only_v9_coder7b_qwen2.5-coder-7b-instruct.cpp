#include<bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<n;++i)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h,w,q; cin >> h >> w >> q;
    vector<vector<bool>> grid(h,vector<bool>(w,true));

    while(q--){
        int r,c; cin >> r >> c;
        --r,--c;

        if(grid[r][c]){
            grid[r][c]=false;
            continue;
        }

        int dr[]={-1,1,0,0},dc[]={0,0,-1,1};

        forn(k,4){
            int x=r,y=c;
            while(true){
                x+=dr[k]; y+=dc[k];
                if(x<0 || x>=h || y<0 || y>=w) break;
                if(grid[x][y]) break;
                grid[x][y]=true;
            }
        }
    }

    int ans=0;
    forn(i,h)forn(j,w)if(grid[i][j])ans++;
    
    cout << ans << endl;
    return 0;
}