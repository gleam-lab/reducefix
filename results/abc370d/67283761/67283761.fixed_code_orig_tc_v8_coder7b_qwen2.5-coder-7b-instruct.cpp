#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 5;

struct Query {
    int type, x, y;
};

struct Point {
    int x, y, dist;
    bool operator<(const Point &other) const {
        return dist > other.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<Query> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].x >> queries[i].y;
        --queries[i].x;
        --queries[i].y;
    }

    vector<vector<int>> destroyed(h, vector<int>(w, 0));
    priority_queue<Point> pq;

    for (int i = 0; i < q; ++i) {
        if (grid[queries[i].x][queries[i].y]) {
            grid[queries[i].x][queries[i].y] = false;
            continue;
        }

        pq.emplace(queries[i].x, queries[i].y, 0);
        while (!pq.empty()) {
            auto [x, y, dist] = pq.top();
            pq.pop();

            if (destroyed[x][y] != dist || !grid[x][y]) continue;

            destroyed[x][y] = INT_MAX;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if (destroyed[nx][ny] != dist + 1) {
                        destroyed[nx][ny] = dist + 1;
                        pq.emplace(nx, ny, dist + 1);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] && destroyed[i][j] == 0) ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}