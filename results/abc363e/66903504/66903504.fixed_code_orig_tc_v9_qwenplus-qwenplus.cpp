#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = int64_t;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Total area of the island
    ll total_area = 1LL * H * W;

    // visited array to mark land that has already sunk
    vector<vector<bool>> sunk(H, vector<bool>(W, false));

    // Priority queues for each year
    vector<queue<pair<int, int>>> Q(Y + 2);

    // Initialize borders: all cells on the border sink in their respective years
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                Q[A[i][j]].push({i, j});
                sunk[i][j] = true;
                total_area--;
            }
        }
    }

    // Process each year from 1 to Y
    for (int y = 1; y <= Y; ++y) {
        while (!Q[y].empty()) {
            auto [i, j] = Q[y].front();
            Q[y].pop();

            const int dx[] = {-1, 0, 1, 0};
            const int dy[] = {0, 1, 0, -1};

            for (int dir = 0; dir < 4; ++dir) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];

                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj]) {
                    int h = A[ni][nj];
                    if (h <= y) {
                        // This cell sinks now
                        sunk[ni][nj] = true;
                        total_area--;

                        // Schedule propagation
                        Q[y].push({ni, nj});
                    } else {
                        // Will sink when its height is reached
                        Q[h].push({ni, nj});
                        sunk[ni][nj] = true;
                        total_area--;
                    }
                }
            }
        }
        cout << total_area << "\n";
    }

    return 0;
}