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

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Add all border cells to the priority queue
    for (int i = 0; i < H; ++i) {
        if (!vis[i][0]) {
            pq.push({A[i][0], {i, 0}});
            vis[i][0] = true;
        }
        if (!vis[i][W - 1]) {
            pq.push({A[i][W - 1], {i, W - 1}});
            vis[i][W - 1] = true;
        }
    }
    for (int j = 0; j < W; ++j) {
        if (!vis[0][j]) {
            pq.push({A[0][j], {0, j}});
            vis[0][j] = true;
        }
        if (!vis[H - 1][j]) {
            pq.push({A[H - 1][j], {H - 1, j}});
            vis[H - 1][j] = true;
        }
    }

    int ans = H * W;
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto current = pq.top();
            pq.pop();
            int h = current.first;
            int x = current.second.first;
            int y = current.second.second;
            --ans;
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0];
                int ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}