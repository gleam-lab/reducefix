#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
bool visited[MAXN][MAXN];

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > sea_level && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) != 1) continue;
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
                if (A[nx][ny] > sea_level) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> result(Y + 1, 0);
    for (int i = 1; i <= Y; ++i) {
        memset(visited, false, sizeof(visited));
        bfs(i);
        int count = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!visited[j][k]) {
                    ++count;
                }
            }
        }
        result[i] = count;
    }

    for (int i = Y; i > 0; --i) {
        result[i] += result[i + 1];
        cout << result[i] << "\n";
    }

    return 0;
}