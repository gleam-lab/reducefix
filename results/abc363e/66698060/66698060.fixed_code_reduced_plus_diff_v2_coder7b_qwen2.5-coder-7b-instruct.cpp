#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m, k;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));

void bfs(vector<vector<bool>>& visited, int x, int y, int targetLevel) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] <= targetLevel) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int level = 1; level <= k; ++level) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] > level) {
                    bfs(visited, i, j, level);
                    ++count;
                }
            }
        }
        cout << count << '\n';
    }
    
    return 0;
}