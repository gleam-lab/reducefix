#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

using pair_type = pair<int, pair<int, int>>; // elevation, row, col

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    priority_queue<pair_type, vector<pair_type>, greater<pair_type>> pq;
    vector<vector<int>> vis(H, vector<int>(W, 0));
    int total_area = H * W;

    // Initialize the priority queue with all cells that are adjacent to the sea
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1) || (j == 0 || j == W - 1)) {
                pq.emplace(A[i][j], {i, j});
                vis[i][j] = 1;
                total_area--;
            }
        }
    }

    // Process the sinking each year
    for (int i = 0; i < Y; ++i) {
        while (!pq.empty()) {
            int elev = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            // Update the total area
            total_area -= 1;

            // Check and mark the adjacent cells
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < H && nc >= 0 && nc < W && A[nr][nc] <= elev + 1 && !vis[nr][nc]) {
                        pq.emplace(A[nr][nc], {nr, nc});
                        vis[nr][nc] = 1;
                        total_area--;
                    }
                }
            }
        }
        cout << total_area << '\n';
    }

    return 0;
}