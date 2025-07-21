#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area, int target) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] > target) {
                visited[i][j] = true;
                q.push({i, j});
                ++area;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto& [dx, dy] : vector<pair<int, int>>{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] > target) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            ++area;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> grid[i][j];

    vector<int> result(y);
    for (int target = 1; target <= y; ++target) {
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        int area = 0;
        bfs(grid, visited, area, target);
        result[target - 1] = area;
    }

    for (int i = 0; i < y; ++i)
        cout << h * w - result[i] << '\n';

    return 0;
}