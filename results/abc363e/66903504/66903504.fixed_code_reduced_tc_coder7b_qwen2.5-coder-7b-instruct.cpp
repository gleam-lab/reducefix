#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 10;
const int INF = 1e9;

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
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    vector<queue<pair<int, int>>> Q(MAX);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            Q[A[i][j]].push({i, j});
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
                    if (!visited[ni][nj]) {
                        visited[ni][nj] = true;
                        Q[max(A[ni][nj], y)].push({ni, nj});
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}