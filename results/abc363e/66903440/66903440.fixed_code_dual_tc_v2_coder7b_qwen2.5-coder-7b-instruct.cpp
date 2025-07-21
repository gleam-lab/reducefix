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

    int ans = H * W;
    vector<bool> F(H * W, true);
    queue<pair<int, int>> Q;

    // Initialize the boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i * W + j] = false;
                Q.push({i, j});
            }
        }
    }

    for (int y = 1; y <= Y; ++y) {
        int size = Q.size();
        while (size--) {
            auto [i, j] = Q.front();
            Q.pop();
            ans--;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                    int index = ni * W + nj;
                    if (F[index]) {
                        F[index] = false;
                        Q.push({ni, nj});
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}