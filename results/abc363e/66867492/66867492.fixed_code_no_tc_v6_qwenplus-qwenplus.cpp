#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using pii = pair<int, int>;
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
    for (auto& row : A) for (auto& x : row) cin >> x;

    // visited matrix to mark cells that have been processed
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Min-heap priority queue to process cells in increasing order of elevation
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Mark and add all boundary cells (adjacent to the sea)
    for (int i = 0; i < H; ++i) {
        for (int j : {0, W - 1}) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                pq.emplace(A[i][j], i * W + j); // store value and position (flattened index)
            }
        }
    }

    for (int j = 1; j < W - 1; ++j) {
        for (int i : {0, H - 1}) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                pq.emplace(A[i][j], i * W + j);
            }
        }
    }

    int remaining = H * W;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    // For each year from 1 to Y, we simulate the rising sea level
    vector<int> result(Y);
    vector<int> events(100001, 0);  // max A[i][j] is 1e5

    // Process the flooding using multi-source BFS with priority queue
    while (!pq.empty()) {
        auto [height, pos] = pq.top();
        pq.pop();

        int r = pos / W;
        int c = pos % W;

        for (int k = 0; k < 4; ++k) {
            int nr = r + dx[k];
            int nc = c + dy[k];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
                visited[nr][nc] = true;
                if (A[nr][nc] <= height) {
                    // This cell will be submerged at the same time as current cell
                    pq.emplace(height, nr * W + nc);
                    remaining--;
                } else {
                    // This cell will submerge only when sea level reaches its height
                    pq.emplace(A[nr][nc], nr * W + nc);
                }
            }
        }
        events[height]++;
    }

    // Precompute cumulative destruction per year
    vector<int> destroyed_up_to(Y + 2, 0);
    for (int y = 1; y <= Y; ++y) {
        destroyed_up_to[y] = destroyed_up_to[y - 1] + events[y];
        result[y - 1] = remaining + H * W - destroyed_up_to[y];
    }

    // Output results
    for (int y = 0; y < Y; ++y) {
        cout << result[y] << "\n";
    }

    return 0;
}