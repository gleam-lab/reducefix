#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(12);
    }
} init;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (auto& row : A) {
        for (auto& x : row) {
            cin >> x;
        }
    }

    // Binary search over time to find when each cell disappears
    vector<vector<int>> disappear_year(H, vector<int>(W, Y + 1));

    // For each boundary cell, perform a BFS to determine when interior cells disappear
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize queue with boundary cells and mark them as visited
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                q.emplace(i, j);
                visited[i][j] = true;
                disappear_year[i][j] = A[i][j];  // The year this cell disappears
            }
        }
    }

    // BFS using min-heap logic via priority queue
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for (const auto& coord : q) {
        int i = coord.first, j = coord.second;
        pq.emplace(disappear_year[i][j], i, j);
    }

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    while (!pq.empty()) {
        auto [year, x, y] = pq.top();
        pq.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                // The disappearance year is max of neighbor's year and the cell's elevation
                int new_year = max(year, A[nx][ny]);
                disappear_year[nx][ny] = new_year;
                pq.emplace(new_year, nx, ny);
            }
        }
    }

    // Count how many cells are above sea level at each year
    vector<int> cnt(Y + 2, H * W);  // Start with all cells above water

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (disappear_year[i][j] <= Y) {
                cnt[disappear_year[i][j]]--;
            }
        }
    }

    // Cumulative decrease
    for (int y = 1; y <= Y; ++y) {
        cnt[y] = min(cnt[y], cnt[y - 1]);
        cout << cnt[y] << '\n';
    }

    return 0;
}