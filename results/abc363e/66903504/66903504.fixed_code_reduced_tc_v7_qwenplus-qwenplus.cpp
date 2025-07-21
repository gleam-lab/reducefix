#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize remaining area
    int ans = H * W;

    // Visited grid to mark sections under water
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Queue for BFS processing at each year
    vector<queue<pair<int, int>>> year_queue(Y + 2);  // up to Y+1

    // Initialize the outer edges (connected to sea)
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                year_queue[A[i][j]].push({i, j});
            }
        }
    }

    // Direction vectors for 4-directional movement
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    // Process each year using BFS
    for (int year = 1; year <= Y; ++year) {
        queue<pair<int, int>> q = year_queue[year];

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            ans--;

            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    int max_level = max(A[nx][ny], year);
                    if (max_level <= Y) {
                        year_queue[max_level].push({nx, ny});
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}