#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> height(h, vector<int>(w));
    vector<vector<int>> sink_year(h, vector<int>(w, INT_MAX));

    // Priority queue to process cells using Dijkstra-like approach
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;

    // Directions: up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Initialize border cells with their sink year
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink_year[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    // Visited matrix to prevent reprocessing
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Process the priority queue to determine when each cell sinks
    while (!pq.empty()) {
        auto [year, pos] = pq.top();
        auto [r, c] = pos;
        pq.pop();

        if (visited[r][c]) continue;
        visited[r][c] = true;

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc]) {
                // The new sink year is max of current cell's sink year and neighbor's effective sink year
                int new_sink_year = min(sink_year[nr][nc], max(year, height[nr][nc]));
                if (new_sink_year < sink_year[nr][nc]) {
                    sink_year[nr][nc] = new_sink_year;
                    pq.push({new_sink_year, {nr, nc}});
                }
            }
        }
    }

    // Count how many cells sink in each year
    vector<int> sink_count(y + 2, 0);  // sink_count[i] = number of cells sinking in year i
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink_year[i][j] <= y) {
                sink_count[sink_year[i][j]]++;
            }
        }
    }

    // Compute cumulative sum to get total sunk by year i
    vector<ll> cum_sum(y + 2, 0);
    for (int i = 1; i <= y; ++i) {
        cum_sum[i] = cum_sum[i - 1] + sink_count[i];
    }

    // Output remaining area for each year
    for (int i = 1; i <= y; ++i) {
        cout << (ll)(h * w) - cum_sum[i] << '\n';
    }

    return 0;
}