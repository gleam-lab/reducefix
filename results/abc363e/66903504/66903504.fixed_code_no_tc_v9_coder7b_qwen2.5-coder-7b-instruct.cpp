#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
bool F[MAXN][MAXN];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!F[i][j] && A[i][j] <= sea_level) {
                q.push({i, j});
                F[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !F[nx][ny] && A[nx][ny] <= sea_level) {
                q.push({nx, ny});
                F[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        memset(F, 0, sizeof(F));
        bfs(sea_level);
        int remaining_area = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (!F[i][j])
                    ++remaining_area;
        cout << remaining_area << endl;
    }

    return 0;
}