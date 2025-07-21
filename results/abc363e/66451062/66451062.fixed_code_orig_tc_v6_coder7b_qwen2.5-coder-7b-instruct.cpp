#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, val;
    bool operator<(const Node& other) const {
        return val > other.val;
    }
};

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int level, int& area) {
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (!visited[i][j] && grid[i][j] <= level) {
                q.emplace(i, j);
                visited[i][j] = true;
                area++;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& d : dir) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !visited[nx][ny] && grid[nx][ny] <= level) {
                q.emplace(nx, ny);
                visited[nx][ny] = true;
                area++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<int> levels(y);
    for (int i = 0; i < y; ++i) {
        levels[i] = i + 1;
    }

    sort(levels.begin(), levels.end());

    vector<int> results(y);
    for (int i = 0; i < y; ++i) {
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        int area = 0;
        bfs(grid, visited, levels[i], area);
        results[i] = h * w - area;
    }

    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}