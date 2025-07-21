#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int H, W, Y;
int A[MAXN][MAXN];
bool F[MAXN][MAXN];

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (!F[i][j] && A[i][j] <= sea_level) {
                q.push({i, j});
                F[i][j] = true;
            }
    
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = p.first + dx[k], nj = p.second + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !F[ni][nj] && A[ni][nj] <= sea_level) {
                F[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];
    
    memset(F, 0, sizeof F);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
                F[i][j] = true;
    
    for (int y = 1; y <= Y; ++y) {
        bfs(y);
        int ans = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (!F[i][j])
                    ++ans;
        cout << ans << '\n';
    }
    
    return 0;
}