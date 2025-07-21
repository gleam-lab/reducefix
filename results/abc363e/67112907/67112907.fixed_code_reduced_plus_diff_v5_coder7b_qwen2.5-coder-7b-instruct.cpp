#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Cell {
    int height, x, y;
    bool operator<(const Cell& other) const {
        return height > other.height;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> grid(H, vector<int>(W));
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Cell> pq;
    for(int i = 0; i < H; ++i){
        pq.push({grid[i][0], i, 0});
        pq.push({grid[i][W-1], i, W-1});
    }
    for(int j = 0; j < W; ++j){
        pq.push({grid[0][j], 0, j});
        pq.push({grid[H-1][j], H-1, j});
    }
    
    while(!pq.empty()){
        auto [height, x, y] = pq.top();
        pq.pop();
        if(visited[x][y]) continue;
        visited[x][y] = true;
        for(auto [dx, dy]: vector<pair<int,int>>{{1,0},{-1,0},{0,1},{0,-1}}){
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]){
                pq.push({grid[nx][ny], nx, ny});
            }
        }
    }
    
    vector<int> result(Y+1, 0);
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(!visited[i][j]){
                result[grid[i][j]]++;
            }
        }
    }
    
    for(int i = 1; i <= Y; ++i){
        result[i] += result[i-1];
    }
    
    for(int i = 1; i <= Y; ++i){
        cout << result[Y-i] << endl;
    }
    
    return 0;
}