#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directions for moving in the grid: right, left, down, up
const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Cell {
    int x, y, height;
};

bool cellComparator(const Cell &a, const Cell &b) {
    return a.height > b.height; // Max-heap based on height
}

void simulateInundation(vector<vector<int>> &grid, int H, int W, int Y) {
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    priority_queue<Cell, vector<Cell>, cellComparator> maxHeap;
    int initialArea = H * W;

    // Push all grid cells into the max heap
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            maxHeap.push({i, j, grid[i][j]});
        }
    }

    // Visited cells are those below the sea level
    while (!maxHeap.empty()) {
        Cell current = maxHeap.top();
        maxHeap.pop();

        if (visited[current.x][current.y]) continue;
        visited[current.x][current.y] = true;

        for (auto &dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;

            // Check if the neighbor is within bounds and hasn't been visited
            if (newX >= 0 && newX < H && newY >= 0 && newY < W && !visited[newX][newY]) {
                // If the neighbor's height is less than or equal to the current height, add it to the heap
                if (grid[newX][newY] <= current.height) {
                    visited[newX][newY] = true;
                    maxHeap.push({newX, newY, grid[newX][newY]});
                }
            }
        }
    }

    // Calculate the area of the island above the sea level after Y years
    for (int year = 0; year < Y; ++year) {
        while (!maxHeap.empty()) {
            Cell current = maxHeap.top();
            maxHeap.pop();

            if (current.height <= year) continue;

            for (auto &dir : directions) {
                int newX = current.x + dir.first;
                int newY = current.y + dir.second;

                if (newX >= 0 && newX < H && newY >= 0 && newY < W) {
                    if (grid[newX][newY] <= current.height && !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        maxHeap.push({newX, newY, grid[newX][newY]});
                    }
                }
            }
            break; // Only need to process the next year's increments
        }
        cout << (H * W) - maxHeap.size() << endl; // The remaining area above the sea level
    }
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    simulateInundation(grid, H, W, Y);

    return 0;
}