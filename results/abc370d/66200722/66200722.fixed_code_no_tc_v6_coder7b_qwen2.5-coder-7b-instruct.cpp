#include <iostream>
#include <vector>
#include <unordered_map>
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
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (parent[pu] > parent[pv]) swap(pu, pv);
        parent[pu] += parent[pv];
        parent[pv] = pu;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    vector<UnionFind> row UF_h(h);
    vector<UnionFind> col UF_w(w);

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!row[r].same(r, c)) {
            row[r].unite(r, c);
            col[c].unite(r, c);
        } else {
            int root = row[r].find(r);
            int up = -1, down = -1, left = -1, right = -1;

            if (root > 0 && !row[root - 1].same(root, root - 1)) {
                up = root - 1;
            }
            if (root + 1 < h && !row[root + 1].same(root, root + 1)) {
                down = root + 1;
            }
            if (root > 0 && !col[root - 1].same(root, root - 1)) {
                left = root - 1;
            }
            if (root + 1 < w && !col[root + 1].same(root, root + 1)) {
                right = root + 1;
            }

            if (up != -1) {
                row[up].unite(up, root);
                col[root].unite(up, root);
            }
            if (down != -1) {
                row[down].unite(down, root);
                col[root].unite(down, root);
            }
            if (left != -1) {
                col[left].unite(left, root);
                row[root].unite(left, root);
            }
            if (right != -1) {
                col[right].unite(right, root);
                row[root].unite(right, root);
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        remainingWalls += row[i].parent.size();
    }
    for (int j = 0; j < w; ++j) {
        remainingWalls += col[j].parent.size();
    }

    cout << remainingWalls << endl;

    return 0;
}