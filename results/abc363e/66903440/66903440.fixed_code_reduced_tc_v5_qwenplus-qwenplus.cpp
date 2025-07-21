#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int H, W, Y;
const int MAX_H = 1005;
const int MAX_W = 1005;

// Directions: up, right, down, left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> A(MAX_H, vector<int>(MAX_W));
vector<vector<bool>> is_sunk(MAX_H, vector<bool>(MAX_W, false));

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> H >> W >> Y;

    rep(i, H) rep(j, W) cin >> A[i][j];

    // Create a queue for each elevation level
    vector<queue<pair<int, int>>> queues(100010);

    // Initialize the border cells as sunk
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            is_sunk[i][j] = true;
            queues[A[i][j]].push({i, j});
        }
    }

    int remaining = H * W;

    for (int y = 1; y <= Y; ++y) {
        while (!queues[y].empty()) {
            auto [x, y_coord] = queues[y].front();
            queues[y].pop();
            remaining--;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y_coord + dy[d];

                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !is_sunk[nx][ny]) {
                    is_sunk[nx][ny] = true;
                    queues[max(y, A[nx][ny])].push({nx, ny});
                }
            }
        }

        cout << remaining << "\n";
    }
}