#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> water(H, vector<int>(W, 0)); // To store water level

    // Find the highest point to set the initial sea level
    int highest_point = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] > highest_point) highest_point = A[i][j];
        }
    }
    int sea_level = highest_point;

    // Process each year
    for (int year = 1; year <= Y; year++) {
        sea_level++; // Increase sea level
        vector<vector<bool>> visited(H, vector<bool>(W, false)); // To store visited points
        queue<pair<int, int>> q; // Queue for BFS
        int remaining_area = 0;

        // Fill the queue with the border points that are above sea level
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && A[i][j] > sea_level) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                if (A[i][j] > sea_level && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                    remaining_area++; // This part is not yet under water
                }
            }
        }

        // Process the queue
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > sea_level) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << endl;
    }

    return 0;
}