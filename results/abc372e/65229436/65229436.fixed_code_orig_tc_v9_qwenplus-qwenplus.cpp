#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr)
#define int long long

struct UnionFind {
    vector<int> parent, size;
    vector<multiset<int, greater<int>>> components;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components.resize(n);
        for (int i = 0; i < n; ++i) {
            components[i].insert(i);
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;

        // Always merge smaller into larger
        if (size[pu] < size[pv]) swap(pu, pv);

        for (int val : components[pv]) {
            components[pu].insert(val);
        }
        parent[pv] = pu;
        size[pu] += size[pv];
        components[pv].clear(); // clear out after merge
        return true;
    }

    int kth_largest(int v, int k) {
        int root = find(v);
        if ((int)components[root].size() < k) return -1;

        auto it = components[root].begin();
        advance(it, k - 1);
        return *it;
    }
};

signed main() {
    IOS;
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            cout << uf.kth_largest(v, k) + 1 << '\n';
        }
    }

    return 0;
}