#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));

void bfs(int n, int m, int k) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] <= k) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dr[dir], nc = c + dc[dir];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] <= k) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<int> heights;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            heights.push_back(grid[i][j]);
        }
    }
    sort(heights.begin(), heights.end());
    heights.erase(unique(heights.begin(), heights.end()), heights.end());
    vector<int> areas(heights.size() + 1);
    areas[heights.size()] = n * m;
    for (int i = heights.size() - 1; i > 0; --i) {
        bfs(n, m, heights[i]);
        areas[i] = areas[i + 1] - count_if(heights.begin(), heights.end(), [&](int x){return x > heights[i];});
    }
    for (int i = 0; i < k; ++i) {
        cout << areas[i + 1] << '\n';
    }
    return 0;
}