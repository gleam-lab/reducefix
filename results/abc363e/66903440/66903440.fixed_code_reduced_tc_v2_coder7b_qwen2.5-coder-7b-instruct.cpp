#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1010;
const int MAXY = 100001;

int H, W, Y;
vector<vector<int>> A(MAXN, vector<int>(MAXN));
vector<vector<bool>> F(MAXN, vector<bool>(MAXN, true));
vector<queue<pair<int, int>>> Q(MAXY + 1);

void bfs(int y) {
    while (!Q[y].empty()) {
        auto [i, j] = Q[y].front();
        Q[y].pop();
        F[i][j] = false;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && F[ni][nj]) {
                F[ni][nj] = false;
                Q[max(A[ni][nj], y)].push({ni, nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                F[i][j] = false;
                Q[A[i][j]].push({i, j});
            }
        }
    }

    int ans = H * W;
    for (int y = 1; y <= Y; ++y) {
        bfs(y);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (F[i][j]) --ans;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}