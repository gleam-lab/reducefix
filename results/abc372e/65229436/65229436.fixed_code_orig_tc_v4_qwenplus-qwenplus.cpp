#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<multiset<int, greater<int>>> components;

    UnionFind(int n) : parent(n) {
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

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;

        // Always merge smaller into larger
        if (components[rx].size() < components[ry].size())
            swap(rx, ry);

        for (int val : components[ry])
            components[rx].insert(val);
        components[ry].clear();
        parent[ry] = rx;
    }

    int query_kth(int v, int k) {
        int root = find(v);
        if (components[root].size() < (size_t)k)
            return -1;

        auto it = components[root].begin();
        advance(it, k - 1);
        return *it + 1; // Convert from 0-based index
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    vector<string> output;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            output.push_back(to_string(uf.query_kth(v - 1, k)));
        }
    }

    for (const string& line : output)
        cout << line << '\n';

    return 0;
}