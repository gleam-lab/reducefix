#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int sea_level) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int nx = cx + dx, ny = cy + dy;
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
                if (grid[nx][ny] > sea_level || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> grid[i][j];

    vector<int> result(y + 1, h * w);
    for (int k = 1; k <= y; ++k) {
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (grid[i][j] <= k && !visited[i][j])
                    bfs(grid, visited, i, j, k);

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (!visited[i][j])
                    --result[k];
    }

    for (int i = 1; i <= y; ++i)
        cout << result[i] << '\n';

    return 0;
}