#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1001;
int H, W, Y;
int grid[MAXN][MAXN];

// Directions for moving in the grid
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// Priority queue to store the cells to be processed
// Each element is a pair of negative elevation and coordinates (i, j)
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

// Function to add a cell to the priority queue
void enqueue(int i, int j) {
    pq.push({-grid[i][j], {i, j}});
}

// Function to process sinking cells and their adjacent cells
void process_sinking_cells() {
    while (!pq.empty() && pq.top().first >= 0) {
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();

        // Mark the current cell as sunk
        grid[i][j] = -1;

        // Attempt to sink adjacent cells
        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d], nj = j + dy[d];
            if (0 <= ni && ni < H && 0 <= nj && nj < W && grid[ni][nj] > 0) {
                grid[ni][nj]--;
                enqueue(ni, nj);
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
            // Initialize the priority queue with all boundary cells and the bottom row
            if (i == 0 || j == 0 || j == W - 1 || i == H - 1) {
                enqueue(i, j);
            }
        }
    }

    for (int year = 0; year < Y; ++year) {
        process_sinking_cells();
        // Output the remaining area of the island
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] > 0) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << endl;
    }

    return 0;
}