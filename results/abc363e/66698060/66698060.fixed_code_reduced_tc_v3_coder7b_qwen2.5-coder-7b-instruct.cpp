#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int h, w, y;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
bool visited[MAXN][MAXN];

void bfs(int x, int y, int targetLevel) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= targetLevel) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] > 0) pq.push({grid[i][j], {i, j}});
        }
    }
    
    while (y--) {
        int targetLevel = pq.top().first;
        pq.pop();
        
        memset(visited, false, sizeof(visited));
        bfs(targetLevel, pq.top().second.first, pq.top().second.second);
        
        int count = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] > targetLevel && !visited[i][j]) {
                    count++;
                    bfs(grid[i][j], i, j);
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}