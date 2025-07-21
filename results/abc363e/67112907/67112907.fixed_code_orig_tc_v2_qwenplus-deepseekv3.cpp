#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

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
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Add all border cells to the priority queue
    for (int i = 0; i < H; ++i) {
        if (!vis[i][0]) {
            pq.emplace(A[i][0], i, 0);
            vis[i][0] = true;
        }
        if (!vis[i][W - 1]) {
            pq.emplace(A[i][W - 1], i, W - 1);
            vis[i][W - 1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        if (!vis[0][j]) {
            pq.emplace(A[0][j], 0, j);
            vis[0][j] = true;
        }
        if (!vis[H - 1][j]) {
            pq.emplace(A[H - 1][j], H - 1, j);
            vis[H - 1][j] = true;
        }
    }

    int ans = H * W;
    for (int y = 1; y <= Y; ++y) {
        while (!pq.empty()) {
            auto [h, i, j] = pq.top();
            if (h > y) break;
            pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (vis[ni][nj]) continue;
                vis[ni][nj] = true;
                pq.emplace(A[ni][nj], ni, nj);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}