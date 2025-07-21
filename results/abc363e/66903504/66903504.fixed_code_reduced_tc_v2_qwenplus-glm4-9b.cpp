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

    // Directions for checking adjacent cells
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    // Queue for BFS
    queue<pair<int, int>> q;
    // Visited matrix
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the queue with the cells that are on the border or have elevation <= sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) || A[i][j] <= 0) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    // Process the queue
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (const auto& dir : directions) {
            int dx = x + dir.first;
            int dy = y + dir.second;
            if (dx >= 0 && dx < H && dy >= 0 && dy < W && !visited[dx][dy] && A[dx][dy] > 0) {
                q.push({dx, dy});
                visited[dx][dy] = true;
            }
        }
    }

    // Calculate the remaining area above sea level
    long long remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && A[i][j] > 0) {
                remaining_area++;
            }
        }
    }

    // Output the result for each year
    for (int year = 1; year <= Y; ++year) {
        cout << remaining_area << endl;
    }

    return 0;
}