#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent;
    UnionFind(int n) : parent(n, -1) {}

    int find(int u) {
        if (parent[u] < 0) return u;
        return parent[u] = find(parent[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (parent[u] > parent[v]) swap(u, v);
            parent[u] += parent[v];
            parent[v] = u;
        }
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    UnionFind uf(h * w);
    vector<map<int, int>> s(h), t(w);

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!s[r].contains(c)) {
            int id = r * w + c;
            s[r][c] = id;
            t[c][r] = id;

            if (r > 0 && s[r - 1].contains(c)) {
                uf.unite(id, s[r - 1][c]);
            }
            if (r < h - 1 && s[r + 1].contains(c)) {
                uf.unite(id, s[r + 1][c]);
            }
            if (c > 0 && t[c - 1].contains(r)) {
                uf.unite(id, t[c - 1][r]);
            }
            if (c < w - 1 && t[c + 1].contains(r)) {
                uf.unite(id, t[c + 1][r]);
            }
        } else {
            int id = s[r][c];
            int leader = uf.find(id);

            int leftmost = leader, rightmost = leader;
            for (int i = c - 1; i >= 0; --i) {
                if (t[i].contains(r) && uf.find(t[i][r]) == leader) {
                    leftmost = t[i][r];
                } else break;
            }
            for (int i = c + 1; i < w; ++i) {
                if (t[i].contains(r) && uf.find(t[i][r]) == leader) {
                    rightmost = t[i][r];
                } else break;
            }

            int topmost = leader, bottommost = leader;
            for (int i = r - 1; i >= 0; --i) {
                if (s[i].contains(c) && uf.find(s[i][c]) == leader) {
                    topmost = s[i][c];
                } else break;
            }
            for (int i = r + 1; i < h; ++i) {
                if (s[i].contains(c) && uf.find(s[i][c]) == leader) {
                    bottommost = s[i][c];
                } else break;
            }

            s[r].erase(c);
            t[c].erase(r);

            if (leftmost != leader) {
                uf.unite(leftmost, leader);
            }
            if (rightmost != leader) {
                uf.unite(rightmost, leader);
            }
            if (topmost != leader) {
                uf.unite(topmost, leader);
            }
            if (bottommost != leader) {
                uf.unite(bottommost, leader);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (uf.parent[i * w + j] < 0) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}