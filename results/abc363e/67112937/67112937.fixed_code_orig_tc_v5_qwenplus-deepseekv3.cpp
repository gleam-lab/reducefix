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

    // Push all border cells into the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    int ans = H * W;
    for (int year = 1; year <= Y; year++) {
        while (!pq.empty() && pq.top()[0] < year) {
            auto [h, x, y] = pq.top();
            pq.pop();
            ans--;
            
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0];
                int ny = y + d[k][1];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({A[nx][ny], nx, ny});
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}