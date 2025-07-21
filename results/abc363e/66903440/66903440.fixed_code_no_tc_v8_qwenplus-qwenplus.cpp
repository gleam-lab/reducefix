#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
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

    // Remaining land cells
    int ans = total;

    // true if cell is still above sea level
    vector<vector<bool>> alive(H, vector<bool>(W, true));

    // For each elevation from 1 to 1e5, we store the list of coordinates (i,j)
    vector<vector<pair<int, int>>> at_height(100002); // up to 1e5 + some buffer
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            at_height[A[i][j]].push_back({i, j});
        }
    }

    // We will use BFS flood fill to simulate sinking
    queue<pair<int, int>> q;

    // Step 1: mark borders as sunk initially
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                alive[i][j] = false;
                q.push({i, j});
                --ans;
            }
        }
    }

    // Process years in increasing order
    for (int year = 1; year <= Y; ++year) {
        // Add all cells with elevation == year to process
        for (auto [i, j] : at_height[year]) {
            if (alive[i][j]) {
                alive[i][j] = false;
                q.push({i, j});
                --ans;
            }
        }

        // Flood fill with BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && alive[nx][ny]) {
                    alive[nx][ny] = false;
                    q.push({nx, ny});
                    --ans;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}