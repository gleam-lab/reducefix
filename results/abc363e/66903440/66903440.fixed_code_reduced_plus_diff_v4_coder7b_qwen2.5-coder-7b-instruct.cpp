#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize the queue and visited array
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> Q(Y + 1);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                Q[A[i][j]].push({i, j});
                visited[i][j] = true;
            }
        }
    }

    // Directions for moving up, down, left, right
    const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int y = 1; y <= Y; ++y) {
        while (!Q[y].empty()) {
            auto [i, j] = Q[y].front();
            Q[y].pop();

            for (const auto &dir : directions) {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && A[ni][nj] <= y) {
                    Q[y].push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }

        // Calculate the remaining area
        int remaining_area = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << endl;
    }

    return 0;
}