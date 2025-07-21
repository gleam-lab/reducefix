#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> sunk(H, vector<bool>(W, false));

    // Read the elevation data and mark boundary cells as sunk
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                sunk[i][j] = true;
            }
        }
    }

    // Queue for BFS, starting with all boundary cells that are sunk
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (sunk[i][j]) {
                q.push({i, j});
            }
        }
    }

    // Simulate the sinking each year
    while (!q.empty() && Y-- > 0) {
        int level = q.size();
        while (level-- > 0) {
            auto [i, j] = q.front();
            q.pop();

            // Explore neighbors
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W && !sunk[ni][nj] && A[ni][nj] <= A[i][j]) {
                        sunk[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }

    // Calculate the area of the island that remains above sea level
    int remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!sunk[i][j]) {
                remaining_area++;
            }
        }
    }

    cout << remaining_area << endl;

    return 0;
}