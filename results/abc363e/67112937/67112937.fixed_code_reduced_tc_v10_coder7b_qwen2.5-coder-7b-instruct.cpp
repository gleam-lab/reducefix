#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int A[MAXN][MAXN];
bool visited[MAXN][MAXN];
int H, W, Y;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int start_i, int start_j, int sea_level) {
    queue<pair<int, int>> q;
    q.push({start_i, start_j});
    visited[start_i][start_j] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0];
            int ny = y + d[k][1];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                visited[nx][ny] = true;
                q.push({nx, ny});
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

    for (int year = 1; year <= Y; ++year) {
        memset(visited, false, sizeof(visited));

        // Mark sections that sink
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] <= year) {
                    bfs(i, j, year);
                }
            }
        }

        // Count remaining sections
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << '\n';
    }

    return 0;
}