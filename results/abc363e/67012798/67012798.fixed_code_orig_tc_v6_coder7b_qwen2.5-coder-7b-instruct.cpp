#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n, m, k;

void bfs(int start_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] > start_level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] > start_level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

vector<int> solve() {
    vector<int> result(k);
    for (int level = 0; level < k; ++level) {
        bfs(level);
        result[level] = n * m - count_if(begin(visited), end(visited), [](auto &v){return v;});
        fill(begin(visited), end(visited), false);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k;
    grid.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    auto result = solve();
    for (int res : result) {
        cout << res << '\n';
    }

    return 0;
}