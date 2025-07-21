#include <iostream>
#include <vector>
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

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int remaining_area = h * w;

    for (int year = 1; year <= y; ++year) {
        vector<pair<int, int>> sinking_cells; // to store cells that will sink this year

        // Mark sinking cells for the current year
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && grid[i][j] <= year) {
                    visited[i][j] = true;
                    sinking_cells.push_back({i, j});

                    // Mark vertically and horizontally adjacent cells if they are also below the current sea level
                    if (i > 0 && grid[i - 1][j] <= year && !visited[i - 1][j]) {
                        visited[i - 1][j] = true;
                        sinking_cells.push_back({i - 1, j});
                    }
                    if (i < h - 1 && grid[i + 1][j] <= year && !visited[i + 1][j]) {
                        visited[i + 1][j] = true;
                        sinking_cells.push_back({i + 1, j});
                    }
                    if (j > 0 && grid[i][j - 1] <= year && !visited[i][j - 1]) {
                        visited[i][j - 1] = true;
                        sinking_cells.push_back({i, j - 1});
                    }
                    if (j < w - 1 && grid[i][j + 1] <= year && !visited[i][j + 1]) {
                        visited[i][j + 1] = true;
                        sinking_cells.push_back({i, j + 1});
                    }
                }
            }
        }

        // Update the remaining area
        for (const auto& cell : sinking_cells) {
            remaining_area--;
        }

        // Output the remaining area for the current year
        cout << remaining_area << endl;
    }

    return 0;
}