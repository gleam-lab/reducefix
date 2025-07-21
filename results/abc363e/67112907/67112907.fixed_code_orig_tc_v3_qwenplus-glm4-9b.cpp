#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using P = pair<int, int>;
using Q = queue<P>;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<P> q;

    // Initialize the queue with cells that are initially submerged
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == 0) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    vector<int> ans(Y, 0);

    // Process the queue and simulate the rising sea level
    for (int year = 0; year < Y; ++year) {
        int remaining_area = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Check all four adjacent cells
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if (visited[nx][ny]) continue;

                    // If the adjacent cell is submerged, mark it and add it to the queue
                    if (A[nx][ny] <= year) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    } else {
                        // Otherwise, it's part of the remaining area
                        remaining_area++;
                    }
                }
            }
        }
        ans[year] = remaining_area;
    }

    // Output the results for each year
    for (int i = 0; i < Y; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}