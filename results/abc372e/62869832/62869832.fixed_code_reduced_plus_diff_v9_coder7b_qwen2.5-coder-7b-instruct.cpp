#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;

struct UF {
    vector<int> parent, rank, size;
    vector<set<int>> neighbors;

    UF(int n) {
        parent.resize(n + 1), rank.resize(n + 1), size.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        fill(rank.begin(), rank.end(), 0);
        fill(size.begin(), size.end(), 1);
        neighbors.resize(n + 1);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        if (rank[px] > rank[py]) {
            parent[py] = px;
            size[px] += size[py];
            neighbors[px].insert(neighbors[py].begin(), neighbors[py].end());
        } else {
            parent[px] = py;
            size[py] += size[px];
            neighbors[py].insert(neighbors[px].begin(), neighbors[px].end());
            if (rank[px] == rank[py]) rank[py]++;
        }
    }

    int kthLargest(int x, int k) {
        int px = find(x);
        if (neighbors[px].size() < k) return -1;
        auto it = neighbors[px].rbegin();
        advance(it, k - 1);
        return *it;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UF uf(n);
    
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 1) {
            uf.unite(u, v);
        } else {
            cout << uf.kthLargest(v, u) << "\n";
        }
    }

    return 0;
}