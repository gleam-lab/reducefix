#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

typedef long long ll;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct Point {
    int y, x;
};

vector<vector<bool>> visited;
vector<vector<int>> grid;
vector<pair<int, Point>> pq;

void bfs(int level, int h, int w) {
    queue<Point> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && grid[i][j] > level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int ny = p.y + (-1, 0, 1, 0)[k];
            int nx = p.x + (0, 1, 0, -1)[k];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (!visited[ny][nx] && grid[ny][nx] > level) {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    grid.resize(h, vector<int>(w));
    visited.resize(h, vector<bool>(w));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < h; ++i) {
        pq.emplace(grid[i][0], Point{i, 0});
        pq.emplace(grid[i][w - 1], Point{i, w - 1});
        visited[i][0] = visited[i][w - 1] = true;
    }

    for (int j = 1; j < w - 1; ++j) {
        pq.emplace(grid[0][j], Point{0, j});
        pq.emplace(grid[h - 1][j], Point{h - 1, j});
        visited[0][j] = visited[h - 1][j] = true;
    }

    int ans = h * w;
    while (!pq.empty()) {
        auto [level, p] = pq.top();
        pq.pop();
        bfs(level, h, w);
        ans -= count(visited.begin(), visited.end(), vector<bool>(w, true));
        if (--y == 0) break;
    }

    cout << ans << endl;
    return 0;
}