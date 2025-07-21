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
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> island(H, vector<bool>(W, true));
    queue<pair<int, int>> q;
    set<int> heights;

    // Initialize the queue with border cells and mark them as visited
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1)) {
                q.push({i, j});
                island[i][j] = false;
                heights.insert(A[i][j]);
            }
        }
    }

    int ans = H * W;

    for (int i = 1; i <= Y; i++) {
        // Process all cells at the current sea level
        while (!q.empty()) {
            ans--;
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
                    continue;
                }

                if (island[nx][ny]) {
                    q.push({nx, ny});
                    island[nx][ny] = false;
                }
            }
        }

        // Add new border cells if the next height is higher
        if (!heights.empty() && *heights.begin() == i) {
            for (int j = 0; j < W; j++) {
                if (island[0][j]) {
                    q.push({0, j});
                    island[0][j] = false;
                }
                if (island[H-1][j]) {
                    q.push({H-1, j});
                    island[H-1][j] = false;
                }
            }
            for (int i = 0; i < H; i++) {
                if (island[i][0]) {
                    q.push({i, 0});
                    island[i][0] = false;
                }
                if (island[i][W-1]) {
                    q.push({i, W-1});
                    island[i][W-1] = false;
                }
            }
            heights.erase(heights.begin());
        }

        cout << ans << endl;
    }

    return 0;
}