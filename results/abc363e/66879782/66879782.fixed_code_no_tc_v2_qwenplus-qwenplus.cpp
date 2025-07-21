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
    
    // Min-heap priority queue: {elevation, {row, col}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Directions for adjacent cells
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Initialize the border cells
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> height[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                sink_year[i][j] = height[i][j];
                pq.push({height[i][j], {i, j}});
            }
        }
    }

    // BFS to propagate sinking
    while (!pq.empty()) {
        auto [current_sea_level, pos] = pq.top();
        auto [r, c] = pos;
        pq.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                // If this cell hasn't been processed yet and can sink now
                if (sink_year[nr][nc] == INT_MAX) {
                    int new_sink_year = max(current_sea_level, height[nr][nc]);
                    sink_year[nr][nc] = new_sink_year;
                    pq.push({new_sink_year, {nr, nc}});
                }
            }
        }
    }

    // Count how many cells sink at each year
    vector<int> sink_count(y + 2, 0); // years from 0 to Y inclusive
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink_year[i][j] <= y) {
                sink_count[sink_year[i][j]]++;
            }
        }
    }

    // Build prefix sum
    for (int i = 1; i <= y; ++i) {
        sink_count[i] += sink_count[i - 1];
    }

    // Output the remaining area for each year
    for (int i = 1; i <= y; ++i) {
        cout << h * w - sink_count[i] << '\n';
    }

    return 0;
}