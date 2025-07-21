#include <bits/stdc++.h>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> island(H, vector<bool>(W, true));
    vector<queue<pair<int, int>>> q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Initialize the queue with the edges of the island
    for (int i = 0; i < H; i++) {
        q.push({i, 0});
        q.push({i, W - 1});
        island[i][0] = island[i][W - 1] = false;
    }
    for (int j = 1; j < W - 1; j++) {
        q.push({0, j});
        q.push({H - 1, j});
        island[0][j] = island[H - 1][j] = false;
    }

    int ans = H * W; // Initially, the whole island is above sea level

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Find the minimum sea level around this section
        int minSeaLevel = INT_MAX;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                minSeaLevel = min(minSeaLevel, A[nx][ny]);
            }
        }

        // Mark the section as sinking if it's not supported by higher ground
        if (A[x][y] < minSeaLevel) {
            ans--;
            island[x][y] = false;
        }

        // If the section is sinking, add its neighbors to the queue
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && island[nx][ny] && A[nx][ny] < minSeaLevel) {
                q.push({nx, ny});
                island[nx][ny] = false;
            }
        }
    }

    // Output the area of the island above sea level for each of the Y years
    for (int i = 1; i <= Y; i++) {
        cout << ans << endl;
    }

    return 0;
}