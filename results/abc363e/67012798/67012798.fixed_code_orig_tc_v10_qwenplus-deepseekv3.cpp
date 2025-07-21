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
    vector<vector<int>> earliest(H, vector<int>(W, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                earliest[i][j] = A[i][j];
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    while (!pq.empty()) {
        auto [val, x, y] = pq.top();
        pq.pop();
        if (val > earliest[x][y]) continue;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (earliest[nx][ny] > max(val, A[nx][ny])) {
                earliest[nx][ny] = max(val, A[nx][ny]);
                pq.emplace(earliest[nx][ny], nx, ny);
            }
        }
    }

    vector<int> count(Y + 2, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (earliest[i][j] <= Y) {
                count[earliest[i][j]]++;
            }
        }
    }

    int remaining = H * W;
    for (int i = 1; i <= Y; i++) {
        remaining -= count[i];
        cout << remaining << '\n';
    }

    return 0;
}