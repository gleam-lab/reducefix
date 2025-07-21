#include<bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank, size, pq;
    int n;

    DSU(int n) : n(n), parent(n + 1), rank(n + 1, 0), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        rank[y] += (rank[x] == rank[y]);
        size[y] += size[x];
        pq[y].insert(pq[x].begin(), pq[x].end());
        pq[y].erase(unique(pq[y].begin(), pq[y].end()), pq[y].end());
        pq[y].push_back(size[y]);
    }

    vector<int> getLargestK(int root, int k) {
        auto &p = pq[root];
        if (p.size() < k) return {-1};
        return {*(--p.end())};
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    DSU dsu(n);

    while (q--) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        if (op == 1) {
            dsu.merge(ix, iy);
        } else {
            auto result = dsu.getLargestK(dsu.find(ix), iy);
            cout << result[0] << "\n";
        }
    }

    return 0;
}