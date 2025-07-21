#include <bits/stdc++.h>

using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W));

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W-1], i, W-1});
    }
    for (int j = 0; j < W; ++j) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H-1][j], H-1, j});
    }

    int ans = H * W;
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        if (h > Y) {
            break;
        }
        pq.pop();
        --ans;
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || vis[nx][ny]) {
                continue;
            }
            vis[nx][ny] = true;
            pq.push({A[nx][ny], nx, ny});
        }
    }

    cout << ans << '\n';

    return 0;
}