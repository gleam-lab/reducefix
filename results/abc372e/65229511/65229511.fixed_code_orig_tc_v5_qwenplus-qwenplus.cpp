#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

struct UnionFind {
    vector<int> parent;
    vector<int> size;
    vector<multiset<int, greater<int>>> components;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i].insert(i);
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

        // Always merge smaller set into larger set
        if (size[pu] < size[pv]) swap(pu, pv);

        // Merge pv into pu
        for (int x : components[pv])
            components[pu].insert(x);
        components[pv].clear();

        parent[pv] = pu;
        size[pu] += size[pv];
        size[pv] = 0;

        return true;
    }

    int kth_largest(int v, int k) {
        int root = find(v);
        if ((int)components[root].size() < k) return -1;

        auto it = components[root].begin();
        advance(it, k - 1);
        return *it + 1; // Convert from 0-based to 1-based index
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    vector<int> ans;

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (t == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            ans.push_back(uf.kth_largest(v, k));
        }
    }

    for (int x : ans)
        cout << x << "\n";

    return 0;
}