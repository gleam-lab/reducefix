#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_Y = 100000;

int h, w, y;
int grid[MAX_H][MAX_W];

int main() {
    cin >> h >> w >> y;
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    // Initialize queue for cells that need to be processed
    queue<pair<int, int>> queue;

    // Initialize vector to keep track of the years cells sink
    vector<vector<int>> sink_years(MAX_H, vector<int>(MAX_W, -1));

    // Mark initial cells that will sink
    for (int i = 0; i < h; ++i) {
        if (grid[i][0] <= y) {
            queue.push({i, 0});
            sink_years[i][0] = 0;
        }
        if (grid[i][w - 1] <= y) {
            queue.push({i, w - 1});
            sink_years[i][w - 1] = 0;
        }
    }
    
    for (int j = 1; j < w - 1; ++j) {
        if (grid[0][j] <= y) {
            queue.push({0, j});
            sink_years[0][j] = 0;
        }
        if (grid[h - 1][j] <= y) {
            queue.push({h - 1, j});
            sink_years[h - 1][j] = 0;
        }
    }
    
    // Process the queue and update sink_years for adjacent cells
    while (!queue.empty()) {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();

        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] > y && sink_years[nx][ny] == -1) {
                    queue.push({nx, ny});
                    sink_years[nx][ny] = y + 1;
                }
            }
        }
    }

    // Count remaining area
    int remaining_area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink_years[i][j] == -1) {
                remaining_area++;
            }
        }
    }

    // Output the remaining area for each year
    for (int year = 0; year < y; ++year) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (sink_years[i][j] == year) {
                    remaining_area--;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}