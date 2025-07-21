#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1100;
int n, m, k;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

struct Node {
    int x, y, height;
    Node(int _x, int _y, int _height) : x(_x), y(_y), height(_height) {}
    bool operator<(const Node& other) const {
        return height > other.height;
    }
};

void bfs(int level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] <= level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    vector<vector<bool>> newVisited(n, vector<bool>(m, false));
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !newVisited[nx][ny] && grid[nx][ny] <= level) {
                q.push({nx, ny});
                newVisited[nx][ny] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (newVisited[i][j]) {
                visited[i][j] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<int> levels(k);
    for (int i = 0; i < k; ++i) {
        cin >> levels[i];
    }

    sort(levels.begin(), levels.end());

    int res = n * m;
    for (int level : levels) {
        bfs(level);
        res -= count_if(begin(visited), end(visited), [](const auto& v) { return accumulate(v.begin(), v.end(), 0); });
        cout << res << endl;
    }

    return 0;
}