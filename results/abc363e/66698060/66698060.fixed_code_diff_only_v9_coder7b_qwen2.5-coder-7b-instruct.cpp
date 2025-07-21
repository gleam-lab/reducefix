#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int h, w, y;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

void bfs(int level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && grid[i][j] > level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] > level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i <= y; ++i) {
        memset(visited, false, sizeof(visited));
        bfs(i);
        int count = 0;
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                if (!visited[j][k]) {
                    ++count;
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}