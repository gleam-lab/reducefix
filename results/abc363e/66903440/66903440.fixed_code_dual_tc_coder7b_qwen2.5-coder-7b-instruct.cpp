#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int totalArea = H * W;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initialize the queue with boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    // Process each year's rise
    for (int y = 1; y <= Y; ++y) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front(); q.pop();
            --totalArea;

            // Explore neighbors
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        if (A[nx][ny] > y) q.push({nx, ny});
                    }
                }
            }
        }
        cout << totalArea << endl;
    }

    return 0;
}