#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()

const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int h,w,q;
    cin>>h>>w>>q;

    vector<vector<bool>> grid(h,vector<bool>(w,true));
    vector<pair<int,int>> cells;

    while(q--){
        int r,c; cin>>r>>c;
        --r;--c;
        if(grid[r][c]) continue;
        grid[r][c]=true;
        for(int d=0;d<4;++d){
            int x=r,y=c;
            while(true){
                x+=dx[d];y+=dy[d];
                if(x<0||x>=h||y<0||y>=w||grid[x][y]) break;
                grid[x][y]=true;
                cells.emplace_back(x,y);
            }
        }
    }

    int ans=0;
    for(auto& [x,y]:cells) ans+=(grid[x][y]?1:-1);
    cout<<ans+h*w-q<<'\n';

    return 0;
}