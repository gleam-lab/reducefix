#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    vector<vector<int>> sea_level(H, vector<int>(W, INT_MAX));

    for (int y = 1; y <= Y; ++y) {
        queue<pair<int, int>> q;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] <= y && sea_level[i][j] == INT_MAX) {
                    q.push({i, j});
                    sea_level[i][j] = y;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (abs(dx) + abs(dy) != 1) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] <= y && sea_level[nx][ny] == INT_MAX) {
                        q.push({nx, ny});
                        sea_level[nx][ny] = y;
                    }
                }
            }
        }
    }

    for (int y = 1; y <= Y; ++y) {
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (sea_level[i][j] > y) ++count;
            }
        }
        cout << count << '\n';
    }

    return 0;
}