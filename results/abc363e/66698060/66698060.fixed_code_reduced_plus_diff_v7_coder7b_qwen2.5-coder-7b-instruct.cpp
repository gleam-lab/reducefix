#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int MAXN = 1010;

int H, W, Y;
int grid[MAXN][MAXN];
int vis[MAXN][MAXN];

vector<PII> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int x, int y, int level) {
    queue<PII> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (auto& [dx, dy] : dir) {
            int nx = cx + dx, ny = cy + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && grid[nx][ny] <= level) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    set<int> levels;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            levels.insert(grid[i][j]);
        }
    }

    vector<int> result(Y);
    for (int level : levels) {
        memset(vis, 0, sizeof(vis));
        bfs(0, 0, level);
        int cnt = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!vis[i][j]) ++cnt;
            }
        }
        result[level - 1] = cnt;
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < Y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}