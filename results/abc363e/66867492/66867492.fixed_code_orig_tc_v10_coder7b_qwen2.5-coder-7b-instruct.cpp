#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const ll infl = 1LL << 60;

template<class T>bool chmax(T&a, const T&b) { if (a < b) { a = b; return true; } return false; }
template<class T>bool chmin(T&a, const T&b) { if (a > b) { a = b; return true; } return false; }

void bfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int y) {
    int n = h.size();
    int m = h[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (!vis[i][0] && h[i][0] <= y) {
            vis[i][0] = true;
            q.emplace(i, 0);
        }
        if (!vis[i][m - 1] && h[i][m - 1] <= y) {
            vis[i][m - 1] = true;
            q.emplace(i, m - 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (!vis[0][i] && h[0][i] <= y) {
            vis[0][i] = true;
            q.emplace(0, i);
        }
        if (!vis[n - 1][i] && h[n - 1][i] <= y) {
            vis[n - 1][i] = true;
            q.emplace(n - 1, i);
        }
    }
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto& [di, dj] : dir) {
            int ni = i + di, nj = j + dj;
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (!vis[ni][nj] && h[ni][nj] <= y) {
                vis[ni][nj] = true;
                q.emplace(ni, nj);
            }
        }
    }
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> hmap(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> hmap[i][j];
        }
    }
    vector<vector<bool>> vis(h, vector<bool>(w));
    for (int t = 1; t <= y; ++t) {
        bfs(hmap, vis, t);
    }
    for (int t = y; t >= 1; --t) {
        bfs(hmap, vis, t);
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!vis[i][j]) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}