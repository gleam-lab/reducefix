#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    // Directions for neighbors: right, left, down, up
    const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Visited array to keep track of cells that have already sunk
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Priority queue to process cells in order of their elevation
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the priority queue with edges of the grid and the first row
    for (int j = 0; j < w; ++j) {
        pq.push({grid[0][j], {0, j}});
        pq.push({grid[h - 1][j], {h - 1, j}});
        visited[0][j] = visited[h - 1][j] = true;
    }

    // Initialize the priority queue with the first column
    for (int i = 1; i < h - 1; ++i) {
        pq.push({grid[i][0], {i, 0}});
        pq.push({grid[i][w - 1], {i, w - 1}});
        visited[i][0] = visited[i][w - 1] = true;
    }

    // Variable to keep track of the number of cells above sea level
    long long count = h * w;

    // Process the cells in the priority queue and increment sea level year by year
    for (int year = 1; year <= y; ++year) {
        // Number of cells that can sink this year
        long long sinkingCells = 0;
        while (!pq.empty() && pq.top().first <= year) {
            auto [elevation, pos] = pq.top();
            pq.pop();
            int i = pos.first;
            int j = pos.second;

            // Check neighbors to see if they can also sink
            for (const auto& dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && !visited[ni][nj] && grid[ni][nj] <= year) {
                    pq.push({grid[ni][nj], {ni, nj}});
                    visited[ni][nj] = true;
                    sinkingCells++;
                }
            }
            count--;
        }
        cout << count - sinkingCells << endl;
    }

    return 0;
}