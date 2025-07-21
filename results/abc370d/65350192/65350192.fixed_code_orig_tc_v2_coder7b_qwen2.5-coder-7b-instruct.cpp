#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y, dist;
    bool operator<(const Cell& other) const { return dist > other.dist; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<priority_queue<Cell>> pq(4);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            pq[0].push({i, j, abs(i) + abs(j)});
            pq[1].push({i, j, abs(i - h + 1) + abs(j)});
            pq[2].push({i, j, abs(i) + abs(j - w + 1)});
            pq[3].push({i, j, abs(i - h + 1) + abs(j - w + 1)});
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!grid[r][c]) continue;

        grid[r][c] = false;

        for (int d = 0; d < 4; ++d) {
            while (!pq[d].empty()) {
                auto [x, y, _] = pq[d].top();
                pq[d].pop();

                if (x == r && y == c) break;

                if (grid[x][y]) {
                    grid[x][y] = false;
                    pq[d].push({x, y, abs(x - r) + abs(y - c)});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j]) ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}