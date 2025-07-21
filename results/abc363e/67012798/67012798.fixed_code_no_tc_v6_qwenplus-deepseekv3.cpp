#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

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

    vector<vector<bool>> sunk(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                sunk[i][j] = true;
            }
        }
    }

    int ans = H * W;
    queue<pair<int, int>> q;
    for (int y = 1; y <= Y; y++) {
        while (!pq.empty() && pq.top().first <= y) {
            auto current = pq.top();
            pq.pop();
            q.push(current.second);
        }

        while (!q.empty()) {
            auto [x, y_curr] = q.front();
            q.pop();
            ans--;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y_curr + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W || sunk[nx][ny]) {
                    continue;
                }

                sunk[nx][ny] = true;
                if (A[nx][ny] <= y) {
                    q.push({nx, ny});
                } else {
                    pq.push({A[nx][ny], {nx, ny}});
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}