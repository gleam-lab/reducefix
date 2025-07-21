#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

using ll = long long;
using pii = pair<int, int>;

const int INF = 1 << 30;

int H, W, Q;

struct UnionFind {
    vector<int> parent;
    vector<int> dir; // 0: up, 1: down, 2: left, 3: right

    UnionFind(int size) : parent(size), dir(size) {
        rep(i, size) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        parent[y] = x;
    }
};

class Solution {
public:
    void main() {
        cin >> H >> W >> Q;
        int N = H * W;
        vector<vector<set<int>>> grid(H + 2, vector<set<int>>(W + 2));

        // Initialize sets for each row and column
        vector<set<int>> rows(H + 2), cols(W + 2);
        rep1(i, H) rep1(j, W) rows[i].insert(j), cols[j].insert(i);

        auto destroy = [&](int r, int c) {
            // Remove from row and column sets
            rows[r].erase(c);
            cols[c].erase(r);
        };

        while (Q--) {
            int r, c;
            cin >> r >> c;

            if (rows[r].find(c) != rows[r].end()) {
                // There's a wall at (r,c)
                destroy(r, c);
            } else {
                // No wall here, destroy adjacent walls
                // Up
                if (!cols[c].empty()) {
                    auto it = cols[c].lower_bound(r);
                    if (it != cols[c].begin()) {
                        --it;
                        destroy(*it, c);
                    }
                }

                // Down
                if (!cols[c].empty()) {
                    auto it = cols[c].lower_bound(r);
                    if (it != cols[c].end()) {
                        destroy(*it, c);
                    }
                }

                // Left
                if (!rows[r].empty()) {
                    auto it = rows[r].lower_bound(c);
                    if (it != rows[r].begin()) {
                        --it;
                        destroy(r, *it);
                    }
                }

                // Right
                if (!rows[r].empty()) {
                    auto it = rows[r].lower_bound(c);
                    if (it != rows[r].end()) {
                        destroy(r, *it);
                    }
                }
            }
        }

        // Count remaining walls
        int ans = 0;
        rep1(i, H) ans += rows[i].size();
        cout << ans << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    sol.main();
    return 0;
}