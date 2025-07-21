#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> sea_level(H, vector<int>(W, 0));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        sea_level[x][y] = 1;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) != 1) continue;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    if (A[nx][ny] <= A[x][y]) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }

    for (int k = 1; k <= Y; ++k) {
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] > k) {
                    count++;
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}