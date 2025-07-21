#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<char>> vis(H, vector<char>(W));

    // Push all border sections into the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = 1;
            }
        }
    }

    int ans = H * W;
    for (int i = 1; i <= Y; i++) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h >= i) break;
            pq.pop();
            ans--;
            for (int j = 0; j < 4; j++) {
                int dx = x + d[j][0], dy = y + d[j][1];
                if (dx < 0 || dx >= H || dy < 0 || dy >= W || vis[dx][dy]) continue;
                vis[dx][dy] = 1;
                pq.push({A[dx][dy], dx, dy});
            }
        }
        cout << ans << '\n';
    }

    return 0;
}