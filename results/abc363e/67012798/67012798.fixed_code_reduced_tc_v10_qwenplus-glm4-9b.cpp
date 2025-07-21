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

    // Initialize the queue with the sections on the boundary and elevation 1
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && A[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int ans = H * W;
    for (int year = 1; year <= Y; year++) {
        if (!q.empty()) {
            int sinked = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (A[x][y] == 1) {
                    ans--;
                    sinked++;
                }
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] > 0) {
                        q.push({nx, ny});
                        A[nx][ny]--;
                    }
                }
            }
            // Accumulate the area of sections that will sink in the next year
            ans += sinked;
        }
        cout << ans << endl;
    }

    return 0;
}