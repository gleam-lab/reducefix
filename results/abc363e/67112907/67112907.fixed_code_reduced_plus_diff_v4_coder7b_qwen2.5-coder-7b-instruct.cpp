#include <bits/stdc++.h>

using namespace std;

struct Node {
    int height, x, y;
    bool operator<(const Node& other) const {
        return height > other.height;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Node> pq;

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        pq.emplace(A[i][0], i, 0);
        pq.emplace(A[i][W - 1], i, W - 1);
    }
    for (int j = 1; j < W - 1; ++j) {
        pq.emplace(A[0][j], 0, j);
        pq.emplace(A[H - 1][j], H - 1, j);
    }

    int result[H][W];
    memset(result, 0, sizeof(result));

    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        if (x == 0 || x == H - 1 || y == 0 || y == W - 1) {
            result[x][y] = 1;
        } else {
            result[x][y] = result[x - 1][y] + result[x + 1][y] + result[x][y - 1] + result[x][y + 1];
        }

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx != 0 && dy != 0) continue;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= height) {
                    pq.emplace(A[nx][ny], nx, ny);
                }
            }
        }
    }

    for (int i = 1; i <= Y; ++i) {
        cout << accumulate(accumulate(result, [](int sum, const vector<int>& row) {
            return sum + accumulate(row.begin(), row.end(), 0);
        }), 0, 0) << '\n';
    }

    return 0;
}