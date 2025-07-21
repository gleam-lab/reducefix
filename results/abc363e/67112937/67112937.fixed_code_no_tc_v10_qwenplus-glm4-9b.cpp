#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // We need to consider the maximum possible elevation change
    // which is Y, so we need to propagate that far.
    vector<vector<int>> vis(H, vector<int>(W, 0));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Start by placing the edges of the grid into the queue
    for (int i = 0; i < H; i++) {
        pq.push({A[i][0], {i, 0}}); // left edge
        pq.push({A[i][W - 1], {i, W - 1}}); // right edge
    }
    for (int j = 0; j < W; j++) {
        pq.push({A[0][j], {0, j}}); // top edge
        pq.push({A[H - 1][j], {H - 1, j}}); // bottom edge
    }

    // Run the simulation for Y years
    for (int year = 1; year <= Y; year++) {
        int remainingArea = 0;
        while (!pq.empty()) {
            auto [elev, pos] = pq.top();
            pq.pop();
            int i = pos.first, j = pos.second;
            if (vis[i][j]) continue; // already visited
            vis[i][j] = 1;
            remainingArea++;

            // Check all adjacent cells
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di, nj = j + dj;
                    if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                    if (vis[ni][nj]) continue;
                    if (A[ni][nj] <= elev + year) {
                        pq.push({A[ni][nj], {ni, nj}});
                    }
                }
            }
        }
        cout << remainingArea << endl;
    }

    return 0;
}