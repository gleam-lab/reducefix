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

    vector<vector<bool>> island(H, vector<bool>(W, true));
    queue<pair<int, int>> q;

    // Initialize the queue with all edge cells and mark them as sinking.
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && A[i][j] <= Y) {
                q.push({i, j});
                island[i][j] = false;
            }
        }
    }

    int ans = H * W;
    while (!q.empty()) {
        int year = q.front().first;
        q.pop();

        // Process only the cells that are sinking in the current year.
        if (year == Y) {
            while (!q.empty()) {
                int x = q.front().second;
                int y = q.front().first;
                q.pop();

                // Check all adjacent cells to see if they should sink.
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] <= year + 1) {
                            island[nx][ny] = false;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            // Remove all sinking cells from the island area.
            ans -= count(island[year].begin(), island[year].end(), true);
        }
    }

    cout << ans << endl;
    return 0;
}