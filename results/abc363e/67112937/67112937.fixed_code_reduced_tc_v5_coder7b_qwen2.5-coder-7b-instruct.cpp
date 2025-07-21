#include <bits/stdc++.h>
using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int MAXN = 1005;

int H, W, Y;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];

void bfs(int sea_level) {
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> q;
    
    // Start BFS from boundary cells
    for (int i = 0; i < H; ++i) {
        if (A[i][0] <= sea_level) q.emplace(i, 0), vis[i][0] = true;
        if (A[i][W-1] <= sea_level) q.emplace(i, W-1), vis[i][W-1] = true;
    }
    for (int j = 0; j < W; ++j) {
        if (A[0][j] <= sea_level) q.emplace(0, j), vis[0][j] = true;
        if (A[H-1][j] <= sea_level) q.emplace(H-1, j), vis[H-1][j] = true;
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + d[k][0], ny = y + d[k][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= sea_level) {
                vis[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    int ans = H * W;
    for (int i = 1; i <= Y; ++i) {
        bfs(i);
        int new_ans = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (!vis[j][k]) ++new_ans;
            }
        }
        cout << new_ans << '\n';
    }
    
    return 0;
}