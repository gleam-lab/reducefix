#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    // Directions for checking adjacent cells: up, down, left, right
    vector<vector<Point>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    // Calculate the initial area above the sea level
    int initial_area = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            bool is_edge = i == 0 || i == H - 1 || j == 0 || j == W - 1;
            if ((is_edge || grid[i][j] > 0) && grid[i][j] > (Y > 0 ? Y : 0)) {
                initial_area++;
            }
        }
    }

    // Output the initial area
    cout << initial_area << endl;

    // Process each year
    for (int year = 1; year < Y; year++) {
        // Prepare a queue for the cells that will sink this year
        queue<Point> to_process;
        // Mark the cells that will sink this year
        vector<vector<bool>> will_sink(H, vector<bool>(W, false));

        // Find the cells that will sink this year
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (grid[i][j] <= year) {
                    will_sink[i][j] = true;
                    // Enqueue all adjacent cells
                    for (auto& dir : directions) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                            to_process.push({ni, nj});
                        }
                    }
                }
            }
        }

        // Process the cells that will sink
        while (!to_process.empty()) {
            Point p = to_process.front();
            to_process.pop();
            // Check all adjacent cells
            for (auto& dir : directions) {
                int ni = p.x + dir[0], nj = p.y + dir[1];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !will_sink[ni][nj] && grid[ni][nj] <= year) {
                    will_sink[ni][nj] = true;
                    to_process.push({ni, nj});
                }
            }
        }

        // Update the initial area and output the result for this year
        initial_area = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!will_sink[i][j] && grid[i][j] > year) {
                    initial_area++;
                }
            }
        }
        cout << initial_area << endl;
    }

    return 0;
}