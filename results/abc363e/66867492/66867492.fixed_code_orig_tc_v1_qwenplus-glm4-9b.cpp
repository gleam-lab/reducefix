#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Priority queue to store pairs of (elevation, row, column)
    priority_queue<pair<int, int, int>, vector<pair<int, int, int>>, greater<pair<int, int, int>>> pq;
    vector<vector<bool>> used(H, vector<bool>(W, false));

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W-1], i, W-1});
        used[i][0] = used[i][W-1] = true;
    }
    for (int j = 1; j < W-1; j++) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H-1][j], H-1, j});
        used[0][j] = used[H-1][j] = true;
    }

    int total_area = H * W;
    while (!pq.empty()) {
        auto [elev, i, j] = pq.top();
        pq.pop();

        // Propagate the sinking to adjacent cells
        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W || used[ni][nj]) continue;
            if (A[ni][nj] <= elev) {
                total_area -= 1; // Subtract the area of the newly submerged cell
                used[ni][nj] = true;
                pq.push({A[ni][nj], ni, nj});
            }
        }
    }

    // Output the remaining area after Y years
    for (int y = 1; y <= Y; y++) {
        cout << total_area << endl;
        // The area remains constant after the initial simulation
    }

    return 0;
}