#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize the BFS queue with the lowest elevation cells on the perimeter
    queue<pair<int, int>> Q;
    int ans = 0;

    // Fill Q with the cells that will sink at sea level 1
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || j == 0 || i == H - 1 || j == W - 1) && A[i][j] > 0) {
                Q.push({i, j});
            }
        }
    }

    // Process the BFS for Y years
    for (int year = 1; year <= Y; ++year) {
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            ans--;  // The current cell sinks

            // Check and add adjacent cells that will also sink
            for (int dx : {-1, 0, 1}) {
                for (int dy : {-1, 0, 1}) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] <= year + 1) {
                        A[nx][ny] = -1;  // Mark the cell as sunk
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
    return 0;
}