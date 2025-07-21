#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int H, W, Y;
int A[MAXN][MAXN];
bool F[MAXN][MAXN];

void bfs(int y) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!F[i][j] && A[i][j] > y) {
                q.push({i, j});
                F[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !F[ni][nj] && A[ni][nj] > y) {
                q.push({ni, nj});
                F[ni][nj] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];
    
    memset(F, 0, sizeof(F));
    for (int i = 0; i < H; ++i) {
        F[i][0] = F[i][W - 1] = true;
        F[0][i] = F[H - 1][i] = true;
    }
    
    for (int y = 1; y <= Y; ++y) {
        bfs(y);
        int cnt = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                if (!F[i][j]) ++cnt;
        cout << cnt << '\n';
    }
    
    return 0;
}