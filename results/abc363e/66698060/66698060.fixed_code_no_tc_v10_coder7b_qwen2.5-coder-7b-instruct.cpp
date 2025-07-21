#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];

bool vis[MAXN][MAXN];
vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!vis[i][j] && A[i][j] > sea_level) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] > sea_level) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        memset(vis, false, sizeof(vis));
        bfs(sea_level);
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!vis[i][j]) {
                    ++remaining_area;
                }
            }
        }
        cout << remaining_area << '\n';
    }

    return 0;
}