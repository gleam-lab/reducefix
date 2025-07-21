#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

void bfs(vector<vector<int>>& height, vector<vector<bool>>& visited, int& ans, int target) {
    int n = height.size();
    int m = height[0].size();
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    // Enqueue all cells with height less than or equal to target
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && height[i][j] <= target) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    // Perform BFS to count all connected components
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        ans++;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && height[nx][ny] <= target) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    vector<int> areas(y + 1, 0);

    for (int t = 1; t <= y; ++t) {
        int ans = 0;
        bfs(height, visited, ans, t);
        areas[t] = ans;
    }

    for (int i = 1; i <= y; ++i) {
        cout << h * w - areas[i] << '\n';
    }

    return 0;
}