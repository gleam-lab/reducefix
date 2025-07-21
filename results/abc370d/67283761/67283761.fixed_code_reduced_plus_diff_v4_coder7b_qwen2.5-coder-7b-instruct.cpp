#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

struct Wall {
    int x, y, dist;
};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H, vector<bool>(W, true));
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!grid[r][c]) continue;

        queue<Wall> q;
        q.emplace(r, c, 0);
        grid[r][c] = false;

        while (!q.empty()) {
            auto [x, y, dist] = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (!isValid(nx, ny, H, W)) continue;

                if (dist == 0 || (dist > 0 && grid[nx][ny])) {
                    q.emplace(nx, ny, dist + 1);
                    grid[nx][ny] = false;
                }
            }
        }
    }

    int remainingWalls = 0;
    for (const auto& row : grid) {
        for (bool cell : row) {
            if (cell) remainingWalls++;
        }
    }

    cout << remainingWalls << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}