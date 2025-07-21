#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

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
    vector<vector<bool>> F(H, vector<bool>(W, true));
    vector<queue<pair<int, int>>> Q(Y + 1);

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
            ans--;

            for (int k = 0; k < 8; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < H && nj >= 0 && nj < W && F[ni][nj]) {
                    F[ni][nj] = false;
                    Q[max(A[ni][nj], y)].push({ni, nj});
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}