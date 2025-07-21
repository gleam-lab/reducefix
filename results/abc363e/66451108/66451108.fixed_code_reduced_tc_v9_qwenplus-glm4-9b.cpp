#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Directions for moving in the grid (left, up, right, down)
    vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    // Queue for BFS
    queue<pair<int, int>> q;

    // Initialize the queue with cells that are on the boundary or directly adjacent to the sea
    for (int i = 0; i < H; ++i) {
        q.push({i, 0});
        q.push({i, W - 1});
    }
    for (int j = 1; j < W - 1; ++j) {
        q.push({0, j});
        q.push({H - 1, j});
    }

    // Visited matrix to keep track of visited cells
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Mark initial boundary as visited
    for (int i = 0; i < H; ++i) {
        visited[i][0] = visited[i][W - 1] = true;
    }
    for (int j = 1; j < W - 1; ++j) {
        visited[0][j] = visited[H - 1][j] = true;
    }

    // Process each year
    for (int year = 0; year < Y; ++year) {
        int remaining_area = 0;
        queue<pair<int, int>> new_q;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Check all 4 adjacent cells
            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Check if the cell is within bounds and not visited
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    if (A[nx][ny] > A[x][y]) { // The cell is higher, mark it as visited
                        visited[nx][ny] = true;
                        new_q.push({nx, ny});
                    } else if (A[nx][ny] <= A[x][y]) { // The cell is sinking
                        remaining_area += 1;
                    }
                }
            }
        }

        // Update the queue with new sinking cells
        q = new_q;

        // Output the remaining area for this year
        cout << remaining_area << endl;
    }

    return 0;
}