#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int MAXY = 100005;

int H, W, Y;
int A[MAXN][MAXN];
bool F[MAXN][MAXN];
vector<queue<pair<int, int>>> Q(MAXY);

void bfs(int y) {
    while (!Q[y].empty()) {
        auto [i, j] = Q[y].front();
        Q[y].pop();
        F[i][j] = false;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && F[ni][nj]) {
                F[ni][nj] = false;
                Q[max(y, A[ni][nj])].push({ni, nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;
    rep(i, H) rep(j, W) cin >> A[i][j];

    int ans = H * W;
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            F[i][j] = false;
            Q[A[i][j]].push({i, j});
        }
    }

    for (int y = 1; y <= Y; ++y) {
        bfs(y);
        ans -= H * W - accumulate(&F[0][0], &F[H][W], 0);
        cout << ans << endl;
    }

    return 0;
}