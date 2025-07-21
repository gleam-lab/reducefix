#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;
const int MAX_Y = 100000;

int H, W, Y;
int grid[MAX_N][MAX_N];
vector<pair<int, pair<int, int>>> pq; // Pair of elevation, and pair of coordinates

// Directions for moving in the grid
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void simulateYear() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> visited(H, vector<int>(W, 0));

    // Add boundary cells and highest elevation cells to the priority queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || grid[i][j] == max_element(grid[0], grid[H - 1])[-1]) {
                pq.push({grid[i][j], {i, j}});
                visited[i][j] = 1;
            }
        }
    }

    while (!pq.empty()) {
        auto [currentHeight, {x, y}] = pq.top();
        pq.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                if (grid[nx][ny] <= currentHeight + 1) { // +1 because sea level rises by 1 each year
                    grid[nx][ny] = min(grid[nx][ny], currentHeight + 1);
                    pq.push({grid[nx][ny], {nx, ny}});
                    visited[nx][ny] = 1;
                }
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    for (int year = 0; year < Y; year++) {
        simulateYear();
    }

    int remainingArea = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] > Y) {
                remainingArea++;
            }
        }
    }

    cout << remainingArea << '\n';

    return 0;
}