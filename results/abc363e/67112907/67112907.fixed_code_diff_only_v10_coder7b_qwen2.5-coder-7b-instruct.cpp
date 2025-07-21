#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int H, W, Y;
int A[N][N];
bool vis[N][N];

void bfs(int sea_level) {
    queue<pair<int, int>> q;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < H; ++i) {
        if (A[i][0] > sea_level) {
            q.push({i, 0});
            vis[i][0] = true;
        }
        if (A[i][W-1] > sea_level) {
            q.push({i, W-1});
            vis[i][W-1] = true;
        }
    }
    for (int j = 1; j < W-1; ++j) {
        if (A[0][j] > sea_level) {
            q.push({0, j});
            vis[0][j] = true;
        }
        if (A[H-1][j] > sea_level) {
            q.push({H-1, j});
            vis[H-1][j] = true;
        }
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto& [dx, dy]: vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] > sea_level) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    for (int sea_level = 0; sea_level <= Y; ++sea_level) {
        bfs(sea_level);
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (vis[i][j]) ++count;
            }
        }
        cout << count << endl;
    }
    
    return 0;
}