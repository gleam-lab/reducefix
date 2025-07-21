#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N=4e5+5,M=1e6+5;
int h,w,q,r,c,nx,ny,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
bool vis[N][N];
vector<PII> g[N];

void bfs(int i,int j){
    queue<PII> q;
    q.push({i,j});
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            nx=x+dx[k],ny=y+dy[k];
            if(nx>=0&&nx<h&&ny>=0&&ny<w&&!vis[nx][ny]){
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>h>>w>>q;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)g[i].push_back({j,i});
    while(q--){
        cin>>r>>c;r--,c--;
        if(vis[r][c])continue;
        vis[r][c]=true;
        bfs(r,c);
    }
    int ans=0;
    for(int i=0;i<h;i++)ans+=g[i].size();
    cout<<ans<<endl;
    return 0;
}