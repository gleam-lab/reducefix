#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Wall {
    int row, col, dist;
};

bool operator<(const Wall& a, const Wall& b) {
    return a.dist > b.dist; // Max-heap based on distance
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H, vector<bool>(W, true));
    priority_queue<Wall> pq;

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert 1-based to 0-based

        if (!grid[r][c]) {
            continue; // No wall to destroy
        }

        grid[r][c] = false;

        // Insert walls to the priority queue for destruction
        pq.push({r, c, 0}); // Starting point with distance 0
        pq.push({r, c - 1, 1}); // Left
        pq.push({r, c + 1, 1}); // Right
        pq.push({r - 1, c, 1}); // Up
        pq.push({r + 1, c, 1}); // Down

        // Process the queue and destroy walls
        while (!pq.empty()) {
            Wall current = pq.top();
            pq.pop();

            // Check if the wall still exists
            if (!grid[current.row][current.col]) {
                continue;
            }

            // Mark the wall as destroyed
            grid[current.row][current.col] = false;
            pq.push({current.row, current.col, current.dist + 1}); // Increase distance for next level

            // Add adjacent walls to the queue
            if (current.row + 1 < H) {
                pq.push({current.row + 1, current.col, current.dist + 1});
            }
            if (current.row - 1 >= 0) {
                pq.push({current.row - 1, current.col, current.dist + 1});
            }
            if (current.col + 1 < W) {
                pq.push({current.row, current.col + 1, current.dist + 1});
            }
            if (current.col - 1 >= 0) {
                pq.push({current.row, current.col - 1, current.dist + 1});
            }
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}