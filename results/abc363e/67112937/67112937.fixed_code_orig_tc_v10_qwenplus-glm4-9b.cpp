#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int H, W, Y;
int grid[1001][1001];

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(H * W, false);

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < H; ++i) {
        pq.push({grid[i][0], i * W});
        pq.push({grid[i][W - 1], i * W + W - 1});
        visited[i * W] = visited[i * W + W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        pq.push({grid[0][j], j});
        pq.push({grid[H - 1][j], (H - 1) * W + j});
        visited[j] = visited[(H - 1) * W + j] = true;
    }

    int remaining_area = H * W;

    while (Y--) {
        int current_level = pq.top().first;
        pq.pop();

        while (!pq.empty() && pq.top().first <= current_level) {
            pq.pop();
        }

        for (int i = 0; i < 4; ++i) {
            int x = pq.top().second / W;
            int y = pq.top().second % W;
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx * W + ny]) {
                if (grid[nx][ny] <= current_level) {
                    pq.push({grid[nx][ny], nx * W + ny});
                    visited[nx * W + ny] = true;
                }
            }
        }

        remaining_area -= pq.size();
        cout << remaining_area << endl;
    }

    return 0;
}