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
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Add all border cells to the priority queue
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        visited[i][0] = true;
        if (W > 1) {
            pq.push({A[i][W-1], i, W-1});
            visited[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        pq.push({A[0][j], 0, j});
        visited[0][j] = true;
        if (H > 1) {
            pq.push({A[H-1][j], H-1, j});
            visited[H-1][j] = true;
        }
    }

    int ans = H * W;
    vector<int> res(Y);

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            if (h >= year) break;
            pq.pop();
            --ans;
            for (int k = 0; k < 4; ++k) {
                int nx = x + d[k][0];
                int ny = y + d[k][1];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                pq.push({A[nx][ny], nx, ny});
            }
        }
        res[year-1] = ans;
    }

    for (int i = 0; i < Y; ++i) {
        cout << res[i] << "\n";
    }

    return 0;
}