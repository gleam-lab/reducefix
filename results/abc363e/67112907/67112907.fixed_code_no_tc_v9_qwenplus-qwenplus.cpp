#include <bits/stdc++.h>

using namespace std;

constexpr int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // We'll use a priority queue to process cells in increasing order of elevation
    using Cell = tuple<int, int, int>; // (elevation, row, col)
    priority_queue<Cell, vector<Cell>, greater<>> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Mark and add all border cells to the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], i, j});
                visited[i][j] = true;
            }
        }
    }

    // total area that will be submerged
    int submerged = 0;
    
    // we need to answer Y queries
    vector<int> result(Y);

    // used to store results for each year
    vector<int> remaining_area(Y + 1, H * W); // initially all cells are above water

    // process in order of increasing elevation
    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        // If height > current year, we'll process it later
        if (height > Y) continue;

        // For this year and all years up to height-1, this cell is submerged
        submerged++;
        remaining_area[height]--;

        // Continue with neighbors only if this is the first time we visit them
        for (auto& dir : d) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.push({A[nx][ny], nx, ny});
            }
        }
    }

    // Fill in any missing values (for years where no new cells were submerged)
    for (int i = 1; i <= Y; ++i) {
        if (remaining_area[i] == 0) {
            remaining_area[i] = remaining_area[i - 1];
        } else {
            remaining_area[i] = min(remaining_area[i], remaining_area[i - 1]);
        }
        cout << remaining_area[i] << "\n";
    }

    return 0;
}