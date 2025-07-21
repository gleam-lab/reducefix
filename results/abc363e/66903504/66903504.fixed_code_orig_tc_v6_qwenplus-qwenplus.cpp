#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = int64_t;
constexpr int INF = 1'000'000'000;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (auto &row : A)
        for (auto &x : row)
            cin >> x;

    // Initialize flooded map and answer
    int ans = H * W;
    vector<vector<bool>> flooded(H, vector<bool>(W, false));

    // Bucketize boundary cells by their elevation
    vector<queue<pair<int, int>>> level_queues(Y + 2);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                level_queues[A[i][j]].push({i, j});
                flooded[i][j] = true;
            }
        }
    }

    // BFS to simulate rising sea levels year by year
    array<int, 4> dx = {1, 0, -1, 0};
    array<int, 4> dy = {0, 1, 0, -1};

    for (int y = 1; y <= Y; ++y) {
        while (!level_queues[y].empty()) {
            auto [i, j] = level_queues[y].front();
            level_queues[y].pop();
            ans--;

            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !flooded[ni][nj]) {
                    if (A[ni][nj] <= y) {
                        flooded[ni][nj] = true;
                        level_queues[max(y, A[ni][nj])].push({ni, nj});
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}