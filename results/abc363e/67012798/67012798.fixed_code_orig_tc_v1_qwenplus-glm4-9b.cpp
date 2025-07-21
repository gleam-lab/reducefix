#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Initialize island array
    vector<vector<bool>> island(H, vector<bool>(W, true));
    deque<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1 || (i > 0 && j > 0 && A[i][j] <= A[i - 1][j] && A[i][j] <= A[i][j - 1])) {
                q.push({i, j});
                island[i][j] = false;
            }
        }
    }

    int ans = H * W;
    while (!q.empty()) {
        int level = q.front().first;
        q.pop();

        // Process all cells at the current sea level
        while (!q.empty() && q.front().first == level) {
            auto [x, y] = q.front();
            q.pop();

            // Process all adjacent cells
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && island[nx][ny]) {
                        if (A[nx][ny] <= level) {
                            island[nx][ny] = false;
                            q.push({nx, ny, level + 1});
                        }
                    }
                }
            }
        }

        // Update the remaining area above sea level
        ans -= count(island.begin(), island.end(), true);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (island[i][j]) {
                    island[i][j] = false;
                }
            }
        }
    }

    // Output the results for each year
    for (int i = 0; i < Y; i++) {
        cout << ans << endl;
        ans -= q.size();
    }

    return 0;
}