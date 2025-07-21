#include <bits/stdc++.h>
using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

    // Initialize priority queue with boundary cells
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W-1], i, W-1});
    }
    for (int j = 1; j < W-1; j++) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H-1][j], H-1, j});
    }

    int ans = H * W;
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        pq.pop();
        if (vis[x][y]) continue;
        vis[x][y] = true;
        ans--;
        for (int k = 0; k < 4; k++) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                pq.push({A[nx][ny], nx, ny});
            }
        }
    }

    vector<int> result(Y);
    result[0] = ans;

    for (int i = 1; i < Y; i++) {
        int h = i + 1;
        bool updated = false;
        for (auto &cell : pq) {
            if (cell[0] <= h) {
                cell[0] = INT_MAX; // Mark as processed
                updated = true;
            } else {
                break;
            }
        }
        if (updated) {
            priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> new_pq;
            for (auto &cell : pq) {
                if (cell[0] != INT_MAX) {
                    new_pq.push(cell);
                }
            }
            pq = new_pq;
            ans -= pq.size();
        }
        result[i] = ans;
    }

    for (int i = 0; i < Y; i++) {
        cout << result[i] << endl;
    }

    return 0;
}