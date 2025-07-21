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

    // Priority queue to store cells sorted by their elevation
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            pq.push({A[i][j], {i, j}});
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    int ans = H * W;

    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();

        if (visited[pos.first][pos.second]) continue;
        visited[pos.first][pos.second] = true;
        ans--;

        for (int d = 0; d < 4; d++) {
            int nx = pos.first + dx[d];
            int ny = pos.second + dy[d];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (visited[nx][ny]) continue;

            pq.push({A[nx][ny], {nx, ny}});
        }
    }

    while (Y--) {
        cout << ans << endl;
    }

    return 0;
}