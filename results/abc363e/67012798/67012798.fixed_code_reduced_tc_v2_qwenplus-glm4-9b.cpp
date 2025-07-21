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

    // Initialize the queue with boundary cells
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        q.push({i, 0});
        q.push({i, W - 1});
        A[i][0] = A[i][W - 1] = 0; // Set boundary cells to sea level
    }
    for (int j = 1; j < W - 1; ++j) {
        q.push({0, j});
        q.push({H - 1, j});
        A[0][j] = A[H - 1][j] = 0; // Set boundary cells to sea level
    }
    
    // Process the queue
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] > 0) {
                if (A[nx][ny] == A[x][y] - 1) {
                    q.push({nx, ny});
                    A[nx][ny] = 0; // Sink the cell
                }
            }
        }
    }

    // Calculate the remaining area of the island
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] > 0) {
                remaining_area++;
            }
        }
    }

    // Output the area for each year
    for (int i = 0; i < Y; ++i) {
        cout << remaining_area << endl;
    }

    return 0;
}