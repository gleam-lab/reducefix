#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Cell {
    int h; // elevation
    int x; // column index
    int y; // row index
};

bool operator>(const Cell& a, const Cell& b) {
    return a.h < b.h; // We use '<' as the priority queue, so the smallest value is at the top.
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
            // Add the borders to the priority queue
            if (i == 0 || j == 0 || i == H - 1 || j == W - 1) {
                pq.push({grid[i][j], j, i});
            }
            // Add the cells not already at sea level to the priority queue
            else {
                pq.push({grid[i][j], j, i});
            }
        }
    }

    int total_area = H * W;

    for (int year = 1; year <= Y; ++year) {
        int current_sea_level = year;
        
        int area_sunk = 0;
        while (!pq.empty()) {
            Cell c = pq.top();
            pq.pop();
            // Check if the current cell's elevation is at or below the current sea level
            if (c.h <= current_sea_level) {
                // Cell will sink, add its area to the total area sunk
                area_sunk += 1;
                // Look at the neighbors
                for (auto& dir : d) {
                    int nx = c.x + dir[0];
                    int ny = c.y + dir[1];
                    // If within bounds and not already visited
                    if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
                        pq.push({grid[ny][nx], nx, ny});
                    }
                }
            }
        }
        // Output the remaining area after this year
        cout << total_area - area_sunk << '\n';
    }

    return 0;
}