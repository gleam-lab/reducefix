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

    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Initialize border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], i, j);
                vis[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    vector<int> result(Y);

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && get<0>(pq.top()) <= year) {
            auto [h, x, y] = pq.top();
            pq.pop();
            if (!vis[x][y]) continue;
            --remaining;

            for (auto& [dx, dy] : d) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.emplace(A[nx][ny], nx, ny);
                }
            }
        }
        result[year - 1] = remaining;
    }

    for (int ans : result) {
        cout << ans << '\n';
    }

    return 0;
}