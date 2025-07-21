#include <bits/stdc++.h>
using namespace std;

void solve(){
    int h,w,q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h,vector<bool>(w,true));
    
    while(q--){
        int r,c;
        cin >> r >> c;
        --r,--c;
        
        if(grid[r][c]) {
            grid[r][c] = false;
            continue;
        }
        
        for(int i=r-1;i>=0;--i){
            if(!grid[i][c]){
                break;
            }
            grid[i][c] = false;
        }
        for(int i=r+1;i<h;++i){
            if(!grid[i][c]){
                break;
            }
            grid[i][c] = false;
        }
        for(int i=c-1;i>=0;--i){
            if(!grid[r][i]){
                break;
            }
            grid[r][i] = false;
        }
        for(int i=c+1;i<w;++i){
            if(!grid[r][i]){
                break;
            }
            grid[r][i] = false;
        }
    }
    int count=0;
    for(auto& row:grid)
        for(bool cell:row)
            if(cell) ++count;
    cout<<count<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}