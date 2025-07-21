#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, elevation;
    Cell(int x, int y, int elevation) : x(x), y(y), elevation(elevation) {}
    bool operator>(const Cell& other) const {
        return elevation > other.elevation; // Use '>' for max heap to prioritize lower elevations
    }
};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));
    vector<vector<bool>> submerged(H, vector<bool>(W, false));

    // Read the grid elevations
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<Cell> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the priority queue with cells that will submerged at year 1
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push(Cell(i, j, grid[i][j]));
                submerged[i][j] = true;
            }
        }
    }

    // Process each year
    for (int year = 1; year <= Y; ++year) {
        vector<pair<int, int>> new_submerged;
        while (!pq.empty()) {
            Cell top = pq.top();
            pq.pop();
            int x = top.x, y = top.y;
            for (int dx = -1; dx <= 1; ++dx) {
                int nx = x + dx;
                for (int dy = -1; dy <= 1; ++dy) {
                    int ny = y + dy;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W || submerged[ny][nx] || visited[ny][nx]) continue;
                    if (grid[ny][nx] <= year) {
                        submerged[ny][nx] = true;
                        new_submerged.emplace_back(nx, ny);
                    }
                }
            }
        }

        // Update the priority queue with new submerged cells
        for (auto p : new_submerged) {
            pq.push(Cell(p.first, p.second, grid[p.first][p.second]));
        }

        // Calculate the remaining area
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!submerged[i][j]) {
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << endl;
    }

    return 0;
}