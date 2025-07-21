#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_Y = 100000;
const int MAX_A = 100000;

int H, W, Y;
vector<vector<int>> A(MAX_H, vector<int>(MAX_W));
vector<vector<bool>> F(MAX_H, vector<bool>(MAX_W, true));

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int ans = H * W;
    vector<queue<pair<int, int>>> Q(MAX_A + 1);

    // Initialize the queue with boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
                Q[A[i][j]].push({i, j});
            }
        }
    }

    for (int y = 1; y <= Y; ++y) {
        while (!Q[y].empty()) {
            auto [i, j] = Q[y].front();
            Q[y].pop();
            --ans;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    if (F[ni][nj]) {
                        F[ni][nj] = false;
                        Q[max(A[ni][nj], y)].push({ni, nj});
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}