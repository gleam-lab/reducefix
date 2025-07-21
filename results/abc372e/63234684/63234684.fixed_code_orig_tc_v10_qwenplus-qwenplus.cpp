#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()

struct UnionFind {
    vector<int> parent, size;
    vector<vector<int>> components;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components.resize(n);
        for (int i = 0; i < n; ++i) {
            components[i].push_back(i);
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        // Always merge smaller into larger
        if (components[x].size() < components[y].size()) swap(x, y);
        // Merge y into x
        components[x].insert(components[x].end(), components[y].begin(), components[y].end());
        sort(components[x].rbegin(), components[x].rend());
        parent[y] = x;
        size[x] += size[y];
        return true;
    }

    int query_kth(int v, int k) {
        int root = find(v);
        if ((int)components[root].size() < k) return -1;
        return components[root][k - 1] + 1; // Convert 0-based index to 1-based node numbering
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    rep(q, Q) {
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
            cout << uf.query_kth(v, k) << '\n';
        }
    }

    return 0;
}