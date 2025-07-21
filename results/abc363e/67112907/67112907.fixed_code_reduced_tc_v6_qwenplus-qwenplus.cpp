#include <bits/stdc++.h>
using namespace std;

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};

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

    // Create a grid to track whether a cell is still above sea level
    vector<vector<bool>> alive(H, vector<bool>(W, true));

    // Store all cells on the border of the island
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                alive[i][j] = false;
                q.emplace(i, j);
            }
        }
    }

    // Build a map from elevation to list of cells at that elevation
    unordered_map<int, vector<pair<int, int>>> elevMap;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            elevMap[A[i][j]].emplace_back(i, j);
        }
    }

    // For each year, we consider cells that sink due to rising sea level
    vector<int> results(Y);
    int remaining = H * W;

    // Sort years in increasing order and process events chronologically
    vector<int> sortedYears(Y);
    iota(sortedYears.begin(), sortedYears.end(), 1);

    // Pointer for processing events in chronological order
    int currElev = 0;

    // Process each year
    for (int year = 0; year < Y; ++year) {
        int currentSeaLevel = year + 1;

        // Add all cells with elevation equal to current sea level to the sinking queue
        while (!elevMap[currentSeaLevel].empty()) {
            auto [x, y] = elevMap[currentSeaLevel].back();
            elevMap[currentSeaLevel].pop_back();

            if (alive[x][y]) {
                alive[x][y] = false;
                --remaining;
                q.emplace(x, y);
            }
        }

        // BFS to propagate sinking
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && alive[nx][ny] && A[nx][ny] <= currentSeaLevel) {
                    alive[nx][ny] = false;
                    --remaining;
                    q.emplace(nx, ny);
                }
            }
        }

        results[year] = remaining;
    }

    for (int res : results) {
        cout << res << '\n';
    }

    return 0;
}