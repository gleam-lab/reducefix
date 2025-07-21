#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w, y;
    cin >> h >> w >> y;

    int height[h][w];
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> height[i][j];

    // Initialize sink_time to a large value (not sinking by default)
    vector<vector<int>> sink_time(h, vector<int>(w, INT_MAX));

    // Priority queue for multi-source BFS from sea
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    // Directions: up, down, left, right
    int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Mark boundary cells and push them into the queue
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink_time[i][j] = height[i][j];
                pq.emplace(height[i][j], i, j);
            }
        }
    }

    // Visited array to avoid reprocessing
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Multi-source BFS to compute when each cell sinks
    while (!pq.empty()) {
        auto [H, r, c] = pq.top();
        pq.pop();

        if (visited[r][c])
            continue;
        visited[r][c] = true;

        for (auto &d : di) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc]) {
                int new_sink_time = min(H, height[nr][nc]);
                if (new_sink_time < sink_time[nr][nc]) {
                    sink_time[nr][nc] = new_sink_time;
                    pq.emplace(new_sink_time, nr, nc);
                }
            }
        }
    }

    // Count how many cells sink at each year
    vector<int> sink_count(y + 2, 0); // y+2 to avoid index issues

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink_time[i][j] <= y)
                sink_count[sink_time[i][j]]++;
        }
    }

    // Compute prefix sum to get total sunk area at each year
    vector<ll> total_sunk(y + 2, 0);
    for (int i = 1; i <= y; ++i)
        total_sunk[i] = total_sunk[i - 1] + sink_count[i];

    // Output remaining area for each year
    ll total_cells = 1LL * h * w;
    for (int i = 1; i <= y; ++i)
        cout << total_cells - total_sunk[i] << '\n';

    return 0;
}