#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int total_area = H * W;
    vector<vector<bool>> F(H, vector<bool>(W, true));

    // Identify initial cells above sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
            }
        }
    }

    // Map to store cells that will sink at each sea level
    map<int, vector<pair<int, int>>> sink_map;

    // Initial setup for sink_map
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (F[i][j]) {
                sink_map[A[i][j]].push_back({i, j});
            }
        }
    }

    // Process each year
    for (int y = 1; y <= Y; ++y) {
        if (sink_map.find(y) != sink_map.end()) {
            for (auto [i, j] : sink_map[y]) {
                F[i][j] = false;
                total_area--;
                // Check neighbors
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W && F[ni][nj]) {
                        sink_map[A[ni][nj]].push_back({ni, nj});
                        F[ni][nj] = false;
                        total_area--;
                    }
                }
            }
        }
        cout << total_area << endl;
    }

    return 0;
}