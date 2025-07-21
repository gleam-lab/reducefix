#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

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
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // visited matrix to mark cells that have already been processed
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    // Initialize the queue with all border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.emplace(A[i][j], make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    // Total number of land cells initially
    int remaining = H * W;

    // Directions for BFS (up, right, down, left)
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    // Process queries over time
    vector<int> results(Y);
    for (int year = 1; year <= Y; ++year) {
        // Process all cells in the queue whose elevation is <= current sea level
        while (!pq.empty() && pq.top().first <= year) {
            auto [elevation, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            remaining--;

            // Explore neighbors
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.emplace(A[nx][ny], make_pair(nx, ny));
                }
            }
        }
        results[year - 1] = remaining;
    }

    // Output results
    for (int res : results) {
        cout << res << '\n';
    }

    return 0;
}