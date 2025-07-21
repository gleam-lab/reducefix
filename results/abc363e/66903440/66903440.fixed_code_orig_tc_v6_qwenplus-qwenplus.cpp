#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using ll = int64_t;
constexpr int INF = 1e9;

int H, W, Y;
vector<vector<int>> A;

// Directions: up, right, down, left
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Cell {
    int r, c, h;
    bool operator<(const Cell& other) const {
        return h < other.h;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    // For each cell, store the earliest year it will be submerged
    vector<vector<int>> submerge_year(H, vector<int>(W, INF));

    // Priority Queue to perform BFS in order of increasing elevation
    priority_queue<Cell> pq;

    // Initialize the boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                submerge_year[i][j] = A[i][j];
                pq.push({i, j, A[i][j]});
            }
        }
    }

    // BFS to propagate submersion times inward
    while (!pq.empty()) {
        auto [r, c, h] = pq.top();
        pq.pop();

        for (int d = 0; d < 4; ++d) {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W) {
                int new_h = max(h, A[nr][nc]);
                if (new_h < submerge_year[nr][nc]) {
                    submerge_year[nr][nc] = new_h;
                    pq.push({nr, nc, new_h});
                }
            }
        }
    }

    // Count how many cells are not submerged yet at each year
    vector<int> ans(Y + 2, H * W);
    map<int, int> submerged_count;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int y = submerge_year[i][j];
            if (y <= Y) {
                submerged_count[y]++;
            }
        }
    }

    // Build the answer from year 1 to Y
    for (int y = 1; y <= Y; ++y) {
        ans[y] = ans[y - 1] - submerged_count[y];
        cout << ans[y] << "\n";
    }

    return 0;
}