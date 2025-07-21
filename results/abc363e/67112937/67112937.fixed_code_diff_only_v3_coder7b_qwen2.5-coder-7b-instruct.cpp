#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) begin(x), end(x)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef long long ll;

const int N = 1e3 + 5;

int n, m, y, a[N][N];
bool vis[N][N];

void bfs(int h) {
    queue<pii> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!vis[i][j] && a[i][j] > h) {
                q.push({i, j});
                vis[i][j] = true;
            }
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto& [dx, dy] : vpii{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] <= h) {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    
    int res = n * m;
    for (int i = 0; i < y; ++i) {
        bfs(i);
        res -= count(all(vis), false);
        cout << res << '\n';
        fill(all(vis), false);
    }
    return 0;
}