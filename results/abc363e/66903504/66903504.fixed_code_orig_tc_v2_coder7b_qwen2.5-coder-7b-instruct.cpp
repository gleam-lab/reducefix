#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>grid;
int n,m,y;
vector<vector<bool>>visited;
queue<pair<int,int>>q;

void bfs(int k){
    while(!q.empty()){
        auto [i,j] = q.front(); q.pop();
        visited[i][j] = true;
        for(auto [di,dj]:{{1,0},{-1,0},{0,1},{0,-1}}){
            int ni = i + di, nj = j + dj;
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(grid[ni][nj] <= k && !visited[ni][nj]) q.push({ni,nj});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> y;
    grid.resize(n,vector<int>(m));
    visited.resize(n,vector<bool>(m,false));

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> grid[i][j];

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j] > y) q.push({i,j});

    while(!q.empty()){
        bfs(q.front().second);
        q.pop();
    }

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!visited[i][j]) cout << n*m-i*j << "\n";
    else cout << 0 << "\n";

    return 0;
}