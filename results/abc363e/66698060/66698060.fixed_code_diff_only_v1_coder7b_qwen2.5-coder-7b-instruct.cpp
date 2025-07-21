#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_Y = 100000;

int H, W, Y;
vector<vector<int>> A(MAX_H, vector<int>(MAX_W));

void bfs(vector<vector<bool>>& visited, int x, int y, int sea_level) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int nx = current.first + i;
                int ny = current.second + j;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
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
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] <= sea_level && !visited[i][j]) {
                    bfs(visited, i, j, sea_level);
                }
            }
        }
        int remaining_area = H * W;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (visited[i][j]) --remaining_area;
            }
        }
        cout << remaining_area << '\n';
    }

    return 0;
}