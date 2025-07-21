#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1000000001;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    int ans = H * W;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> Q(Y + 1);

    rep(i, H) rep(j, W) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            visited[i][j] = true;
            Q[A[i][j]].push({i, j});
        }
    }

    for (int y = 1; y <= Y; ++y) {
        while (!Q[y].empty()) {
            auto [i, j] = Q[y].front();
            Q[y].pop();
            ans--;
            rep(k, 4) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    Q[max(y, A[ni][nj])].push({ni, nj});
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}