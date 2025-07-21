#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int INF = 1 << 30;

struct DSU {
    map<int, int> parent;
    map<int, int> left, right;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void add(int x) {
        if (parent.count(x)) return;
        parent[x] = x;
        left[x] = x;
        right[x] = x;
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (ra > rb) swap(ra, rb);
        left[rb] = left[ra];
        right[rb] = max(right[rb], right[ra]);
        parent[ra] = rb;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> grid(H + 2, vector<int>(W + 2, 0));

    vector<DSU> row(H + 2), col(W + 2);

    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            row[i].add(j);
            col[j].add(i);
        }
    }

    long long total = 1LL * H * W;

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (grid[r][c]) {
            grid[r][c] = 0;
            total--;

            // Try to merge with up
            if (r > 1 && grid[r - 1][c])
                row[r].unite(c, c);

            // Try to merge with down
            if (r < H && grid[r + 1][c])
                row[r].unite(c, c);

            // Try to merge with left
            if (c > 1 && grid[r][c - 1])
                col[c].unite(r, r);

            // Try to merge with right
            if (c < W && grid[r][c + 1])
                col[c].unite(r, r);
        } else {
            grid[r][c] = 0; // already zero

            auto process = [&](int dir) {
                DSU& dsu = (dir < 2 ? col[c] : row[r]);
                int coord = (dir < 2 ? r : c);
                int dr = 0, dc = 0;
                if (dir == 0) dr = -1; // up
                if (dir == 1) dr = +1; // down
                if (dir == 2) dc = -1; // left
                if (dir == 3) dc = +1; // right

                int x = coord + dr;
                int target = (dir < 2 ? r : c);
                while (true) {
                    int cur = (dir < 2 ? x : target);
                    int other = (dir < 2 ? target : x);
                    if ((dir < 2 && (x < 1 || x > H)) || (!dir < 2 && (x < 1 || x > W))) break;
                    if (grid[ (dir < 2 ? x : target) ][ (dir < 2 ? target : x) ]) {
                        int root = dsu.find(cur);
                        int l = dsu.left[root];
                        int r_ = dsu.right[root];
                        for (int i = l; i <= r_; i++) {
                            if (dir < 2) {
                                row[i].unite(c, c);
                            } else {
                                col[i].unite(r, r);
                            }
                        }
                        break;
                    }
                    x += (dir < 2 ? dr : dc);
                }
            };

            for (int d = 0; d < 4; ++d)
                process(d);
        }
    }

    cout << total << endl;
}