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

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        if (!vis[i][0]) pq.emplace(A[i][0], make_pair(i, 0)), vis[i][0] = true;
        if (!vis[i][W-1]) pq.emplace(A[i][W-1], make_pair(i, W-1)), vis[i][W-1] = true;
    }
    for (int j = 0; j < W; ++j) {
        if (!vis[0][j]) pq.emplace(A[0][j], make_pair(0, j)), vis[0][j] = true;
        if (!vis[H-1][j]) pq.emplace(A[H-1][j], make_pair(H-1, j)), vis[H-1][j] = true;
    }

    while (!pq.empty()) {
        auto [height, pos] = pq.top(); pq.pop();
        for (auto &dir : d) {
            int nx = pos.first + dir[0], ny = pos.second + dir[1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= height) {
                pq.emplace(A[nx][ny], make_pair(nx, ny));
                vis[nx][ny] = true;
            }
        }
    }

    int ans = H * W;
    cout << ans << '\n';

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().first <= year) {
            auto [_, pos] = pq.top(); pq.pop();
            --ans;
            for (auto &dir : d) {
                int nx = pos.first + dir[0], ny = pos.second + dir[1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= year) {
                    pq.emplace(A[nx][ny], make_pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}