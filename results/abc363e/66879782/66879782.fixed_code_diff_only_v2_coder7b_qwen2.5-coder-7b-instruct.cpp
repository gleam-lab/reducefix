#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<int> heights(Y + 1, 0);

    // BFS to determine the number of connected components above each height
    for (int k = 1; k <= Y; ++k) {
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < H && !found; ++i)
            for (int j = 0; j < W && !found; ++j) {
                if (!visited[i][j] && A[i][j] > k) {
                    q.push({i, j});
                    visited[i][j] = true;
                    found = true;
                }
            }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; ++dy) {
                    if (abs(dx) + abs(dy) != 1) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] > k) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
        }

        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (visited[i][j])
                    heights[k]++;
    }

    // Calculate the prefix sum of heights to get the area above each sea level
    for (int i = 1; i <= Y; ++i)
        heights[i] += heights[i - 1];

    // Output the area above each sea level
    for (int i = 1; i <= Y; ++i)
        cout << H * W - heights[i] << "\n";

    return 0;
}