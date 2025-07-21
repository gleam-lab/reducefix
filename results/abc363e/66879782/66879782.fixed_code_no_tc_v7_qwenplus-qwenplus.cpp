#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
        }
    }

    // Initialize sink level as infinity and use a priority queue to process from borders
    vector<vector<int>> sink_level(h, vector<int>(w, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;

    // Directions: up, down, left, right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Initialize border cells
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                sink_level[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    // Visited array to avoid reprocessing
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Process the priority queue to determine when each cell sinks
    while (!pq.empty()) {
        auto [current_level, pos] = pq.top();
        pq.pop();
        int r = pos.first, c = pos.second;

        if (visited[r][c]) continue;
        visited[r][c] = true;

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                int new_sink_level = max(current_level, height[nr][nc]);
                if (sink_level[nr][nc] > new_sink_level) {
                    sink_level[nr][nc] = new_sink_level;
                    pq.push({new_sink_level, {nr, nc}});
                }
            }
        }
    }

    // Count how many cells remain above water at each year
    vector<int> remaining(y + 2, 0);  // Index up to Y+1 to avoid overflow
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink_level[i][j] <= y) {
                remaining[sink_level[i][j]]++;
            }
        }
    }

    // Prefix sum: remaining[i] now contains number of cells sunk by year i
    for (int i = 1; i <= y; ++i) {
        remaining[i] += remaining[i - 1];
    }

    // Output the area above water for each year
    for (int i = 1; i <= y; ++i) {
        cout << h * w - remaining[i] << "\n";
    }

    return 0;
}