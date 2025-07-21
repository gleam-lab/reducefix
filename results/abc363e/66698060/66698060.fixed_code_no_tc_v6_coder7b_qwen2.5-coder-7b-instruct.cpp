#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int h, w, y;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

struct Cell {
    int x, y, level;
    bool operator<(const Cell& other) const {
        return level > other.level;
    }
};

void bfs(int startLevel) {
    queue<Cell> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && grid[i][j] <= startLevel) {
                q.push({i, j, grid[i][j]});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = curr.x + dx[k];
            int ny = curr.y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= startLevel) {
                q.push({nx, ny, grid[nx][ny]});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < y; ++i) {
        memset(visited, false, sizeof(visited));
        bfs(i);
        cout << h * w - count_if(visited[0], visited[0] + w, [](bool val){return val;}) << '\n';
    }

    return 0;
}