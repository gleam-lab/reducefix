#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 400000;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) {
                swap(x, y);
            }
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> rows(h), cols(w);
    UnionFind uf(h * w);

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!rows[r].count(c)) {
            rows[r].insert(c);
            cols[c].insert(r);

            if (!cols[c].empty()) {
                auto prev = prev(cols[c].begin());
                uf.unite(rows[*prev].begin(), rows[c].begin());
            }
            if (!cols[c].empty()) {
                auto next = next(cols[c].begin());
                uf.unite(rows[*next].begin(), rows[c].begin());
            }
            if (!rows[r].empty()) {
                auto prev = prev(rows[r].begin());
                uf.unite(cols[*prev].begin(), cols[c].begin());
            }
            if (!rows[r].empty()) {
                auto next = next(rows[r].begin());
                uf.unite(cols[*next].begin(), cols[c].begin());
            }
        } else {
            int component = uf.find(rows[r].begin());
            rows[r].erase(rows[r].find(c));
            cols[c].erase(cols[c].find(r));

            if (!cols[c].empty()) {
                auto prev = prev(cols[c].begin());
                uf.unite(rows[*prev].begin(), rows[c].begin());
            }
            if (!cols[c].empty()) {
                auto next = next(cols[c].begin());
                uf.unite(rows[*next].begin(), rows[c].begin());
            }
            if (!rows[r].empty()) {
                auto prev = prev(rows[r].begin());
                uf.unite(cols[*prev].begin(), cols[c].begin());
            }
            if (!rows[r].empty()) {
                auto next = next(rows[r].begin());
                uf.unite(cols[*next].begin(), cols[c].begin());
            }
        }
    }

    int count = 0;
    for (int i = 0; i < h; ++i) {
        count += rows[i].size();
    }
    for (int j = 0; j < w; ++j) {
        count += cols[j].size();
    }
    cout << h * w - count << endl;

    return 0;
}