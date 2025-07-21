#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    // We will use a queue per year level
    vector<queue<pair<int, int>>> Q(Y + 2);
    vector<vector<bool>> F(H, vector<bool>(W, true));

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
                Q[A[i][j]].push({ i, j });
            }
        }
    }

    int ans = H * W;
    for (int y = 1; y <= Y; ++y) {
        queue<pair<int, int>> q = move(Q[y]);
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            ans--;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && F[ni][nj]) {
                    if (A[ni][nj] <= y) {
                        F[ni][nj] = false;
                        Q[max(A[ni][nj], y)].push({ ni, nj });
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}