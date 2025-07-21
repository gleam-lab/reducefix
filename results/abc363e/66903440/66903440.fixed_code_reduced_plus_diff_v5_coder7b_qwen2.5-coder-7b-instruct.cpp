#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m,y;
vector<vector<int>> grid,sea_level;

void bfs(int level){
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]>level && !sea_level[i][j]){
                q.push({i,j});
                sea_level[i][j] = true;
            }
        }
    }
    
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(auto &[dx,dy]:directions){
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(grid[nx][ny] > level && !sea_level[nx][ny]){
                    q.push({nx,ny});
                    sea_level[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> y;
    grid.resize(n,vector<int>(m));
    sea_level.resize(n,vector<int>(m,false));
    
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> grid[i][j];
    
    for(int i=1;i<=y;i++){
        bfs(i);
        int count = 0;
        for(int j=0;j<n;j++)for(int k=0;k<m;k++)if(!sea_level[j][k])count++;
        cout << count << "\n";
    }
    return 0;
}