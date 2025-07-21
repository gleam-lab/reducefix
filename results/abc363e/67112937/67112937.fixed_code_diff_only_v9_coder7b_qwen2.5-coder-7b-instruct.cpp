#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAXN = 1005;

int H, W, Y;
int A[MAXN][MAXN];
bool vis[MAXN][MAXN];

int bfs(int start_i, int start_j, int target_level) {
    if (A[start_i][start_j] <= target_level) return 0;
    vis[start_i][start_j] = true;
    queue<pii> q;
    q.push({start_i, start_j});
    int area = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : vector<pii>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny] && A[nx][ny] > target_level) {
                vis[nx][ny] = true;
                q.push({nx, ny});
                area++;
            }
        }
    }

    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Y;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < Y; i++) {
        memset(vis, false, sizeof(vis));
        int total_area = 0;
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                if (!vis[j][k]) {
                    total_area += bfs(j, k, i);
                }
            }
        }
        cout << total_area << "\n";
    }

    return 0;
}