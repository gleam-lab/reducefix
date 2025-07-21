#include <iostream>
#include <vector>

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

    int total_area = H * W;
    for (int year = 0; year < Y; ++year) {
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        queue<pair<int, int>> q; // queue of coordinates to process

        // Add cells on the edges of the matrix to the queue
        for (int j = 0; j < W; ++j) {
            if (A[0][j] <= year || A[H-1][j] <= year) q.push({0, j});
            if (A[0][j] <= year || A[H-1][j] <= year) q.push({H-1, j});
        }

        for (int i = 0; i < H; ++i) {
            if (A[i][0] <= year || A[i][W-1] <= year) q.push({i, 0});
            if (A[i][0] <= year || A[i][W-1] <= year) q.push({i, W-1});
        }

        int sunk_area = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Check if the cell is higher than the sea level
            if (A[x][y] > year) {
                // Add adjacent cells to the queue if they are not visited
                if (x > 0 && !visited[x-1][y]) q.push({x-1, y});
                if (x < H-1 && !visited[x+1][y]) q.push({x+1, y});
                if (y > 0 && !visited[x][y-1]) q.push({x, y-1});
                if (y < W-1 && !visited[x][y+1]) q.push({x, y+1});
            } else {
                // The cell is sinking
                visited[x][y] = true;
                ++sunk_area;
            }
        }

        total_area -= sunk_area; // Update the remaining area
        cout << total_area << '\n';
    }

    return 0;
}