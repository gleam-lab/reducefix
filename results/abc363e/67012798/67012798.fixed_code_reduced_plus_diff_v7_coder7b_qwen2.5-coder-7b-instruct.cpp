#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

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
    vector<queue<pair<int, int>>> q(Y + 1);
    
    // Initialize the queues for the initial state where sea level is 0
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1)) {
                q[0].push({i, j});
                island[i][j] = false;
            }
        }
    }

    int ans = H * W;

    for (int h = 1; h <= Y; h++) {
        while (!q[h - 1].empty()) {
            auto [x, y] = q[h - 1].front();
            q[h - 1].pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
                    continue;
                }

                if (island[nx][ny]) {
                    q[h].push({nx, ny});
                    island[nx][ny] = false;
                }
            }
        }

        // Update the answer for the current sea level
        ans -= q[h].size();
        cout << ans << endl;
    }

    return 0;
}