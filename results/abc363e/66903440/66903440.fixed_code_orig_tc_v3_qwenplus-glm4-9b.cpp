#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    cin >> A[0];
    for (int i = 1; i < H; ++i) cin >> A[i];

    vector<vector<bool>> F(H, vector<bool>(W, true));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    // Initialize the queue with the edges and cells with elevation 0
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1 || A[i][j] == 0) {
                F[i][j] = false;
                Q.push({A[i][j], i * W + j});
            }
        }
    }

    int remainingArea = H * W;

    // Process the cells for each year
    for (int y = 1; y <= Y; ++y) {
        while (!Q.empty()) {
            auto [elev, pos] = Q.top();
            Q.pop();
            int r = pos / W; // row
            int c = pos % W; // column

            // Mark all 4 adjacent cells as submerged
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < H && nc >= 0 && nc < W && A[nr][nc] > elev && F[nr][nc]) {
                        F[nr][nc] = false;
                        Q.push({A[nr][nc], nr * W + nc});
                        remainingArea -= 1;
                    }
                }
            }
        }
        cout << remainingArea << endl;
    }
}