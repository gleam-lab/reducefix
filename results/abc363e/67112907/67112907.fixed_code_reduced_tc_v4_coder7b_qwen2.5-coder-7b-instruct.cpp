#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int D[] = {0, 1, 0, -1};
const int DD[] = {1, 0, -1, 0};

struct Cell {
    int h, x, y;
    bool operator<(const Cell& other) const {
        return h > other.h;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<Cell> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        visited[i][0] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.emplace(A[0][j], 0, j);
        visited[0][j] = true;
    }
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][W-1], i, W-1);
        visited[i][W-1] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.emplace(A[H-1][j], H-1, j);
        visited[H-1][j] = true;
    }

    int ans = H * W;
    while (!pq.empty()) {
        auto [h, x, y] = pq.top();
        if (h <= 0) break;
        pq.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + D[k], ny = y + DD[k];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            pq.emplace(A[nx][ny] - (h + 1), nx, ny);
        }
    }

    for (int t = 1; t <= Y; ++t) {
        ans -= pq.size();
        cout << ans << '\n';
    }

    return 0;
}