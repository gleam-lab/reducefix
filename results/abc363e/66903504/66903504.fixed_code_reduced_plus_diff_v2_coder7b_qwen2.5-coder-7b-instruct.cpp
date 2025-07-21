#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
vector<vector<int>> A(MAXN, vector<int>(MAXN));
vector<vector<bool>> F(MAXN, vector<bool>(MAXN, true));

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(vector<vector<bool>>& F, int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!F[i][j] && A[i][j] <= sea_level) {
                F[i][j] = true;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !F[nx][ny] && A[nx][ny] <= sea_level) {
                F[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
            }
        }
    }

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        bfs(F, sea_level);
        int ans = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (F[i][j]) {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}