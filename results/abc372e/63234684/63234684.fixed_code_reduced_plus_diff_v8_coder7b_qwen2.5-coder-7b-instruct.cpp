#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank, size, sorted_children;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        sorted_children.resize(n);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
            update_sorted_children(pu, pv);
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            update_sorted_children(pv, pu);
        } else {
            parent[pu] = pv;
            rank[pv]++;
            size[pv] += size[pu];
            update_sorted_children(pv, pu);
        }
    }

    void update_sorted_children(int parent, int child) {
        auto &children = sorted_children[parent];
        auto it = lower_bound(children.begin(), children.end(), child);
        children.insert(it, child);
        while (children.size() > 9) {
            children.pop_back();
        }
    }

    vector<int> get_k_largest(int u, int k) {
        int pu = find(u);
        if (k > size[pu]) return {-1};
        return {sorted_children[pu][k - 1]};
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--; b--;

        if (ty == 1) {
            uf.merge(a, b);
        } else {
            auto result = uf.get_k_largest(b, a);
            if (!result.empty()) {
                cout << result[0] + 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}