#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) a.begin(), a.end()
typedef long long ll;
using pii = pair<int, int>;

struct UnionFind {
    vector<int> parent, size;
    vector<multiset<int, greater<int>>> components;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i].insert(i);
        }
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;

        // Always merge smaller into larger
        if (size[u] < size[v]) swap(u, v);

        // Merge v into u
        for (int val : components[v]) {
            components[u].insert(val);
        }
        components[v].clear();
        parent[v] = u;
        size[u] += size[v];
        return true;
    }

    int kth_largest(int x, int k) {
        int root = find(x);
        if ((int)components[root].size() < k) return -1;

        auto it = components[root].begin();
        advance(it, k - 1);
        return *it + 1; // Convert 0-based index to 1-based vertex number
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    vector<int> ans;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else {
            int v, k;
            cin >> v >> k;
            ans.push_back(uf.kth_largest(v - 1, k));
        }
    }

    for (int x : ans) cout << x << '\n';
}