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

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Handle all border cells
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> res(Y);
    
    for (int i = 0; i < Y; i++) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h > i+1) break;  // Note: sea level is i+1 in year i (1-based)
            pq.pop();
            ans--;
            for (int j = 0; j < 4; j++) {
                int dx = x + d[j][0], dy = y + d[j][1];
                if (dx >= 0 && dx < H && dy >= 0 && dy < W && !vis[dx][dy]) {
                    vis[dx][dy] = true;
                    pq.push({A[dx][dy], dx, dy});
                }
            }
        }
        res[i] = ans;
    }

    for (int i = 0; i < Y; i++) {
        cout << res[i] << '\n';
    }

    return 0;
}