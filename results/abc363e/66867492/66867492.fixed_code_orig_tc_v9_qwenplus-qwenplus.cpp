#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.precision(12);
    }
} init;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (auto &row : A) {
        for (auto &x : row) {
            cin >> x;
        }
    }

    // We'll use a priority queue to process cells from lowest to highest elevation
    using Cell = tuple<int, int, int>;  // height, row, col
    priority_queue<Cell, vector<Cell>, greater<>> pq;

    // Mark if a cell is on the border
    vector<vector<bool>> is_border(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                is_border[i][j] = true;
                pq.emplace(A[i][j], i, j);
            }
        }
    }

    // Used to mark if a cell is submerged
    vector<vector<bool>> submerged(H, vector<bool>(W, false));

    // Answer array
    vector<int> ans(Y + 2, H * W);  // Start with full area

    // Process the queue
    while (!pq.empty()) {
        auto [h, r, c] = pq.top();
        pq.pop();

        // If already submerged, skip
        if (submerged[r][c]) continue;

        // This cell will be submerged at sea level h
        for (int sea_level = 1; sea_level <= h; ++sea_level) {
            ans[sea_level]--;
        }

        submerged[r][c] = true;

        // Check neighbors
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !submerged[nr][nc]) {
                pq.emplace(A[nr][nc], nr, nc);
            }
        }
    }

    // Print results for each year
    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}