#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> used(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Initialize the priority queue with the lowest cells
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], {i, 0}});
        pq.push({A[i][W - 1], {i, W - 1}});
        used[i][0] = used[i][W - 1] = true;
    }

    for (int j = 0; j < W; ++j) {
        pq.push({A[0][j], {0, j}});
        pq.push({A[H - 1][j], {H - 1, j}});
        used[0][j] = used[H - 1][j] = true;
    }

    int remaining_area = H * W;

    while (Y-- > 0) {
        int max_elevation = -1;

        // Process all cells that are currently at sea level
        while (!pq.empty() && pq.top().first <= (int)Y) {
            auto cell = pq.top();
            pq.pop();

            // Update the remaining area
            remaining_area -= cell.second.first >= 0 && cell.second.first < H &&
                              cell.second.second >= 0 && cell.second.second < W;

            // Update the maximum elevation seen so far
            if (cell.second.first >= 0 && cell.second.first < H &&
                cell.second.second >= 0 && cell.second.second < W) {
                max_elevation = max(max_elevation, A[cell.second.first][cell.second.second]);
            }
        }

        // Process the newly submerged cells
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] <= (int)Y && !used[i][j]) {
                    used[i][j] = true;
                    remaining_area--;
                    pq.push({A[i][j], {i, j}});
                }
            }
        }

        // Output the remaining area after Y years
        cout << remaining_area << '\n';
    }

    return 0;
}