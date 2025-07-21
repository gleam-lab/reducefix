#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int h, w, y;
vector<vector<int>> a(MAXN, vector<int>(MAXN));
bool vis[MAXN][MAXN];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!vis[i][j] && a[i][j] > level) {
                q.emplace(i, j);
                vis[i][j] = true;
            }
        }
    }
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && a[nx][ny] > level) {
                q.emplace(nx, ny);
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    
    int ans = h * w;
    for (int i = 1; i <= y; ++i) {
        bfs(i);
        ans -= count(vis.begin(), vis.end(), vector<bool>(w, true));
        fill(vis.begin(), vis.end(), vector<bool>(w, false));
        cout << ans << "\n";
    }
    
    return 0;
}