#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1005;

int H, W, Y;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] <= Y) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int result = H * W;

    // Start the DFS from the edges
    for (int i = 0; i < H; i++) {
        if (!vis[i][0]) {
            dfs(i, 0);
        }
        if (!vis[i][W-1]) {
            dfs(i, W-1);
        }
        if (i > 0 && !vis[i-1][W-1]) {
            dfs(i-1, W-1);
        }
        if (i < H-1 && !vis[i+1][0]) {
            dfs(i+1, 0);
        }
    }

    for (int year = 1; year <= Y; year++) {
        cout << result - (H * W - H - W + min(H, W)) << endl;
    }

    return 0;
}