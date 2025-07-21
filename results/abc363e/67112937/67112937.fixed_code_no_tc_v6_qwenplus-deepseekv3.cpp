#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    vector<vector<char>> vis(H, vector<char>(W));

    // Initialize the priority queue with all border cells
    for (int j = 0; j < W; ++j) {
        if (!vis[0][j]) {
            pq.emplace(A[0][j], 0, j);
            vis[0][j] = 1;
        }
        if (!vis[H-1][j]) {
            pq.emplace(A[H-1][j], H-1, j);
            vis[H-1][j] = 1;
        }
    }
    for (int i = 1; i < H-1; ++i) {
        if (!vis[i][0]) {
            pq.emplace(A[i][0], i, 0);
            vis[i][0] = 1;
        }
        if (!vis[i][W-1]) {
            pq.emplace(A[i][W-1], i, W-1);
            vis[i][W-1] = 1;
        }
    }

    int ans = H * W;
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h > year) break;
            pq.pop();
            --ans;
            for (int k = 0; k < 4; ++k) {
                int dx = x + d[k][0];
                int dy = y + d[k][1];
                if (dx >= 0 && dx < H && dy >= 0 && dy < W && !vis[dx][dy]) {
                    vis[dx][dy] = 1;
                    pq.emplace(A[dx][dy], dx, dy);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}