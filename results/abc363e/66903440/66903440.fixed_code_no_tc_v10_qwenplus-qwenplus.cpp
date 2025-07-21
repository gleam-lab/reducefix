#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    // Initialize the remaining area
    int ans = H * W;
    vector<vector<bool>> is_submerged(H, vector<bool>(W, false));

    // Bucket queue: year -> list of cells that will be submerged at this year
    vector<queue<pair<int, int>>> q(Y + 2);  // up to Y+1

    // Initially mark borders as submerged and add to appropriate year's queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                if (!is_submerged[i][j]) {
                    is_submerged[i][j] = true;
                    q[A[i][j]].push({i, j});
                }
            }
        }
    }

    // Process each year
    for (int year = 1; year <= Y; ++year) {
        queue<pair<int, int>> process;
        // Move all cells scheduled for this year into a working queue
        while (!q[year].empty()) {
            process.push(q[year].front());
            q[year].pop();
        }

        while (!process.empty()) {
            auto [x, y] = process.front();
            process.pop();
            ans--;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !is_submerged[nx][ny]) {
                    int max_level = max(year, A[nx][ny]);
                    if (max_level <= Y) {
                        is_submerged[nx][ny] = true;
                        q[max_level].push({nx, ny});
                    } else {
                        // Mark temporarily as submerged but won't be processed in this timeline
                        is_submerged[nx][ny] = true;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}