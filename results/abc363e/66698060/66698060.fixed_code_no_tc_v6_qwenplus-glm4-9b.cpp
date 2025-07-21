#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> island(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> island[i][j];
        }
    }

    // Priority queue to simulate the rising sea level, storing pairs of (elevation, i, j)
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<bool>> flooded(h, vector<bool>(w, false));

    // Initialize the priority queue with the edges of the island
    for (int i = 0; i < h; ++i) {
        pq.push({island[i][0], i, 0});
        pq.push({island[i][w - 1], i, w - 1});
        flooded[i][0] = flooded[i][w - 1] = true;
    }
    for (int j = 0; j < w; ++j) {
        pq.push({island[0][j], 0, j});
        pq.push({island[h - 1][j], h - 1, j});
        flooded[0][j] = flooded[h - 1][j] = true;
    }

    int remaining_area = h * w;
    for (int year = 0; year < y; ++year) {
        int sunk_count = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int elevation = top[0], i = top[1], j = top[2];

            // Check if the current cell is already flooded
            if (flooded[i][j]) {
                continue;
            }

            // Update the elevation for the next year
            elevation++;

            // Check adjacent cells
            if (i > 0 && !flooded[i - 1][j] && island[i - 1][j] <= elevation) {
                pq.push({island[i - 1][j], i - 1, j});
                flooded[i - 1][j] = true;
                sunk_count++;
            }
            if (i < h - 1 && !flooded[i + 1][j] && island[i + 1][j] <= elevation) {
                pq.push({island[i + 1][j], i + 1, j});
                flooded[i + 1][j] = true;
                sunk_count++;
            }
            if (j > 0 && !flooded[i][j - 1] && island[i][j - 1] <= elevation) {
                pq.push({island[i][j - 1], i, j - 1});
                flooded[i][j - 1] = true;
                sunk_count++;
            }
            if (j < w - 1 && !flooded[i][j + 1] && island[i][j + 1] <= elevation) {
                pq.push({island[i][j + 1], i, j + 1});
                flooded[i][j + 1] = true;
                sunk_count++;
            }

            // If the current cell is below sea level, it gets flooded
            if (island[i][j] <= elevation) {
                flooded[i][j] = true;
            }
        }

        remaining_area -= sunk_count;
        cout << remaining_area << endl;
    }

    return 0;
}