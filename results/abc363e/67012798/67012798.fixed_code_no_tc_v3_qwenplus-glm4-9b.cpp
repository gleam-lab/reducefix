#include <bits/stdc++.h>

using namespace std;

#define dx {-1, 0, 1, 0}
#define dy {0, 1, 0, -1}

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

    // Initialize the queue with the initial state
    vector<vector<bool>> island(H, vector<bool>(W, true));
    queue<pair<int, int>> q;
    int initialCount = 0;

    // Find all sections on the border of the island
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && A[i][j] == 1) {
                q.push({i, j});
                island[i][j] = false;
                initialCount++;
            }
        }
    }

    // Perform the simulation for Y years
    for (int i = 1; i <= Y; i++) {
        int sunkCount = 0;
        // First, process the current year's flooding
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= H || ny >= W || !island[nx][ny] || A[nx][ny] <= i) {
                    continue;
                }
                island[nx][ny] = false;
                q.push({nx, ny});
                sunkCount++;
            }
        }
        initialCount -= sunkCount;
        cout << initialCount << endl;
    }

    return 0;
}