#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> vis(H, vector<int>(W, 0));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

    // Process nodes on the perimeter
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W - 1], i, W - 1});
        vis[i][0] = vis[i][W - 1] = 1;
    }
    for (int j = 0; j < W; ++j) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H - 1][j], H - 1, j});
        vis[0][j] = vis[H - 1][j] = 1;
    }

    int remaining_area = H * W;
    while (Y--) {
        int next_remaining_area = 0;
        while (!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();

            if (vis[x][y]) {
                continue;
            }

            vis[x][y] = 1;
            next_remaining_area++;

            // Check the four possible neighbors
            for (int dx : {-1, 0, 1}) {
                for (int dy : {-1, 0, 1}) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                        if (A[nx][ny] > height + 1) {
                            pq.push({A[nx][ny], nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        remaining_area = next_remaining_area;
        cout << remaining_area << '\n';
    }

    return 0;
}