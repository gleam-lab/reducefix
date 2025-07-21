#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

struct Cell {
    int x, y, height;
};

bool operator<(const Cell& a, const Cell& b) {
    return a.height > b.height;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    int A[MAXN][MAXN];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<Cell> cells;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cells.push_back({i, j, A[i][j]});
        }
    }

    sort(cells.begin(), cells.end());

    int area[H][W];
    memset(area, 0, sizeof(area));

    for (int k = 0; k < Y; ++k) {
        int h = cells[k].height;
        queue<pair<int, int>> q;
        bool visited[MAXN][MAXN];
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && A[i][j] <= h) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx * dy != 0) continue;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if (visited[nx][ny]) continue;
                    if (A[nx][ny] <= h) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    ++cnt;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}