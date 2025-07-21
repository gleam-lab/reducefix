#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> Cell; // (height, (row, col))

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> island(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> island[i][j];
        }
    }

    priority_queue<Cell, vector<Cell>, greater<>> pq; // Min-heap to store cells by height

    // Initialize the heap with the borders of the island
    for (int i = 0; i < H; ++i) {
        pq.push({island[i][0], {i, 0}});
        pq.push({island[i][W - 1], {i, W - 1}});
    }
    for (int j = 0; j < W; ++j) {
        pq.push({island[0][j], {0, j}});
        pq.push({island[H - 1][j], {H - 1, j}});
    }

    int initialArea = H * W;

    for (int year = 1; year <= Y; ++year) {
        int remainingArea = initialArea;
        vector<vector<bool>> visited(H, vector<bool>(W, false));

        while (!pq.empty()) {
            auto [height, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;

            // If the cell is already visited or its height is greater than the current year, skip it
            if (visited[r][c] || height > year) continue;

            // Mark the cell as visited
            visited[r][c] = true;

            // Check adjacent cells
            if (r > 0 && !visited[r - 1][c] && island[r - 1][c] <= year) {
                pq.push({island[r - 1][c], {r - 1, c}});
            }
            if (r < H - 1 && !visited[r + 1][c] && island[r + 1][c] <= year) {
                pq.push({island[r + 1][c], {r + 1, c}});
            }
            if (c > 0 && !visited[r][c - 1] && island[r][c - 1] <= year) {
                pq.push({island[r][c - 1], {r, c - 1}});
            }
            if (c < W - 1 && !visited[r][c + 1] && island[r][c + 1] <= year) {
                pq.push({island[r][c + 1], {r, c + 1}});
            }
        }

        // Calculate the remaining area
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j] && island[i][j] > year) {
                    ++remainingArea;
                }
            }
        }

        cout << remainingArea << '\n';
    }

    return 0;
}