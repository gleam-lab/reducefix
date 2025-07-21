#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define all(x) begin(x), end(x)

const int INF = 1e9 + 7;

struct Cell {
    int height, x, y;
    bool operator<(const Cell& other) const { return height > other.height; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> grid[i][j];

    priority_queue<Cell> pq;
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    rep(i, w) {
        pq.emplace(grid[0][i], 0, i);
        visited[0][i] = true;
        pq.emplace(grid[h - 1][i], h - 1, i);
        visited[h - 1][i] = true;
    }

    rep(i, h) {
        pq.emplace(grid[i][0], i, 0);
        visited[i][0] = true;
        pq.emplace(grid[i][w - 1], i, w - 1);
        visited[i][w - 1] = true;
    }

    ll ans = h * w;
    while (!pq.empty()) {
        auto [height, x, y] = pq.top();
        pq.pop();

        if (height <= y) break;

        --ans;

        static constexpr array<pair<int, int>, 4> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.emplace(grid[nx][ny], nx, ny);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}