#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
using ld=long double;
const int inf=1000000001;
const ll INF=1e18;

vector<int> dx={1,0,-1,0,1,1,-1,-1};
vector<int> dy={0,1,0,-1,1,-1,1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H,W,Y;
    cin>>H>>W>>Y;
    vector<vector<int>>A(H,vector<int>(W));
    for(int i=0;i<H;++i)
        for(int j=0;j<W;++j)
            cin>>A[i][j];

    int ans=H*W;
    vector<vector<bool>> visited(H,vector<bool>(W,false));
    queue<pair<int,int>> q;
    
    // Collect border cells
    for(int i=0;i<H;++i){
        if(!visited[i][0]) q.push({i,0}), visited[i][0]=true;
        if(!visited[i][W-1]) q.push({i,W-1}), visited[i][W-1]=true;
    }
    for(int j=0;j<W;++j){
        if(!visited[0][j]) q.push({0,j}), visited[0][j]=true;
        if(!visited[H-1][j]) q.push({H-1,j}), visited[H-1][j]=true;
    }

    while(q.size() && Y--){
        int size=q.size();
        while(size--){
            auto [i,j]=q.front(); q.pop();
            --ans;
            for(int k=0;k<4;++k){
                int ni=i+dx[k], nj=j+dy[k];
                if(ni>=0 && ni<H && nj>=0 && nj<W && !visited[ni][nj] && A[ni][nj]<=Y){
                    visited[ni][nj]=true;
                    q.push({ni,nj});
                }
            }
        }
        if(Y) cout << ans << '\n';
    }
    return 0;
}