#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int h, w, y;
int island[MAXN][MAXN];
int sea_level[MAXN][MAXN];
int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    sea_level[r][c] = island[r][c];

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto d : di) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (island[nx][ny] <= island[x][y]) {
                sea_level[nx][ny] = sea_level[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w >> y;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> island[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1 || island[i][j] <= 0) {
                bfs(i, j);
            }
        }
    }

    vector<int> heights(y + 1, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sea_level[i][j] <= y) {
                heights[sea_level[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= y; i++) {
        cout << (h * w - heights[i]) << '\n';
    }

    return 0;
}