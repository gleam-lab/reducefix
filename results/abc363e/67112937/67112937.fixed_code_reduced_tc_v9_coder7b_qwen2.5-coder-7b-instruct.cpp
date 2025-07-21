#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

struct Cell {
    int height, x, y;
    bool operator<(const Cell& other) const {
        return height > other.height;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    priority_queue<Cell> pq;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (A[i][j] == 1) {
                pq.push({1, i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        static constexpr array<pair<int, int>, 4> directions = {{
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        }};

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] == 1) {
                visited[nx][ny] = true;
                pq.push({1, nx, ny});
            }
        }
    }

    int remainingArea = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (visited[i][j]) {
                remainingArea++;
            }
        }
    }

    for (int t = 1; t <= Y; ++t) {
        remainingArea -= min(t, remainingArea);
        cout << remainingArea << '\n';
    }

    return 0;
}