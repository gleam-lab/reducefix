#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    int total_area = H * W;
    vector<vector<bool>> is_land(H, vector<bool>(W, true));
    vector<queue<pair<int, int>>> year_queue(Y + 2); // queues for each possible year

    // Initialize the edge cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                is_land[i][j] = false;
                year_queue[A[i][j]].push({i, j});
            }
        }
    }

    for (int y = 1; y <= Y; ++y) {
        while (!year_queue[y].empty()) {
            auto [i, j] = year_queue[y].front();
            year_queue[y].pop();

            if (total_area > 0)
                --total_area;

            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && is_land[ni][nj]) {
                    // If neighbor's height is <= current sea level, flood it
                    if (A[ni][nj] <= y) {
                        is_land[ni][nj] = false;
                        year_queue[y].push({ni, nj}); // continue BFS
                    } else {
                        // Schedule for future processing
                        year_queue[A[ni][nj]].push({ni, nj});
                        is_land[ni][nj] = false;
                    }
                }
            }
        }
        cout << total_area << "\n";
    }

    return 0;
}