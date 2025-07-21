#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll INF=LLONG_MAX;
const double pi=acos(-1.0);

vector<vector<int>> grid;

bool isValid(int x,int y){
    if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
        return true;
    }
    return false;
}

void dfs(int x,int y){
    stack<pair<int,int>> st;
    st.push({x,y});
    while(!st.empty()){
        auto [cx,cy]=st.top();
        st.pop();
        grid[cx][cy]=-1;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i)!=abs(j)){
                    int nx=cx+i;
                    int ny=cy+j;
                    if(isValid(nx,ny) && grid[nx][ny]==1){
                        st.push({nx,ny});
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h,w,q;
    cin>>h>>w>>q;
    grid.resize(h,vector<int>(w,1));
    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(grid[x][y]==1){
            grid[x][y]=-1;
            dfs(x,y);
        }
    }
    
    int ans=0;
    for(auto &row:grid){
        for(int val:row){
            if(val==1){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}