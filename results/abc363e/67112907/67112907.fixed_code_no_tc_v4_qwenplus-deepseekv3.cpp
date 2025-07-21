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

    // Push all border sections into the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({A[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    int ans = H * W;
    vector<int> result(Y);

    for (int year = 1; year <= Y; year++) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h >= year) break;
            pq.pop();
            ans--;
            for (int k = 0; k < 4; k++) {
                int dx = x + d[k][0];
                int dy = y + d[k][1];
                if (dx >= 0 && dx < H && dy >= 0 && dy < W && !vis[dx][dy]) {
                    vis[dx][dy] = true;
                    pq.push({A[dx][dy], dx, dy});
                }
            }
        }
        result[year-1] = ans;
    }

    for (int i = 0; i < Y; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}