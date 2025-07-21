#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (auto &row : A) {
        for (auto &cell : row) {
            cin >> cell;
        }
    }

    vector<vector<bool>> used(H, vector<bool>(W, false));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        if (!used[i][0]) {
            pq.emplace(A[i][0], i, 0);
            used[i][0] = true;
        }
        if (!used[i][W - 1]) {
            pq.emplace(A[i][W - 1], i, W - 1);
            used[i][W - 1] = true;
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        if (!used[0][j]) {
            pq.emplace(A[0][j], 0, j);
            used[0][j] = true;
        }
        if (!used[H - 1][j]) {
            pq.emplace(A[H - 1][j], H - 1, j);
            used[H - 1][j] = true;
        }
    }

    int ans = H * W;
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    for (int i = 1; i <= Y; ++i) {
        while (!pq.empty() && get<0>(pq.top()) <= i) {
            auto [a, y, x] = pq.top();
            pq.pop();
            --ans;
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W || used[ny][nx]) {
                    continue;
                }
                used[ny][nx] = true;
                pq.emplace(A[ny][nx], ny, nx);
            }
        }
        cout << ans << '\n';
    }
}