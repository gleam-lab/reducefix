#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int A[MAXN][MAXN];
bool F[MAXN][MAXN];
vector<pair<int, int>> Q[202020];

void bfs(int h) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= h && !F[i][j]) {
                F[i][j] = true;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !F[nx][ny] && A[nx][ny] <= h) {
                F[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int H, W, Y; cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (A[i][j] > Y) A[i][j] = Y + 1;
            else Q[A[i][j]].push_back({i, j});
        }
    }
    int ans = H * W;
    for (int h = 1; h <= Y; ++h) {
        bfs(h);
        ans -= Q[h].size();
        cout << ans << '\n';
    }
    return 0;
}