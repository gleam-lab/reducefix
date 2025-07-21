#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define H first
#define W second

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Total number of cells
    int total = H * W;

    // Track if a cell is still above water
    vector<vector<bool>> above(H, vector<bool>(W, true));

    // Queue for each possible sea level
    vector<queue<pair<int, int>>> Q(Y + 2);  // up to Y+1 inclusive

    // Mark border cells as submerged and add to queue
    rep(i, H) {
        rep(j, W) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                above[i][j] = false;
                if (A[i][j] <= Y) {
                    Q[A[i][j]].push({i, j});
                }
            }
        }
    }

    // Directions for BFS (up/down/left/right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Process year by year
    int remaining = total;
    for (int y = 1; y <= Y; ++y) {
        // Process all cells that sink this year
        while (!Q[y].empty()) {
            auto [x, y_coord] = Q[y].front();
            Q[y].pop();
            remaining--;

            // Check neighbors
            rep(d, 4) {
                int nx = x + dx[d];
                int ny = y_coord + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && above[nx][ny]) {
                    above[nx][ny] = false;
                    int neighborLevel = max(y, A[nx][ny]);
                    if (neighborLevel <= Y) {
                        Q[neighborLevel].push({nx, ny});
                    }
                }
            }
        }

        // Output the remaining area above sea level
        cout << remaining << "\n";
    }

    return 0;
}