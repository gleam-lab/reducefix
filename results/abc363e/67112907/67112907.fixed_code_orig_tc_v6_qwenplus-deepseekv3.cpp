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
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Initialize the priority queue with border sections
    for (int i = 0; i < H; i++) {
        if (!vis[i][0]) {
            pq.push({A[i][0], i, 0});
            vis[i][0] = true;
        }
        if (!vis[i][W - 1]) {
            pq.push({A[i][W - 1], i, W - 1});
            vis[i][W - 1] = true;
        }
    }
    for (int j = 0; j < W; j++) {
        if (!vis[0][j]) {
            pq.push({A[0][j], 0, j});
            vis[0][j] = true;
        }
        if (!vis[H - 1][j]) {
            pq.push({A[H - 1][j], H - 1, j});
            vis[H - 1][j] = true;
        }
    }

    int ans = H * W;
    vector<int> res(Y);
    for (int y = 1; y <= Y; y++) {
        while (!pq.empty()) {
            auto [h, x, j] = pq.top();
            if (h > y) break;
            pq.pop();
            ans--;
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0];
                int nj = j + d[k][1];
                if (nx >= 0 && nx < H && nj >= 0 && nj < W && !vis[nx][nj]) {
                    vis[nx][nj] = true;
                    pq.push({A[nx][nj], nx, nj});
                }
            }
        }
        res[y - 1] = ans;
    }

    for (int y = 0; y < Y; y++) {
        cout << res[y] << "\n";
    }

    return 0;
}