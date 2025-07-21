#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<vector<int>> components;

    UnionFind(int n) {
        parent.resize(n);
        components.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i].push_back(i);
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        // Always merge smaller into larger
        if (components[rootX].size() < components[rootY].size())
            swap(rootX, rootY);

        for (int val : components[rootY]) {
            components[rootX].push_back(val);
        }

        // Sort and keep only top 10 values
        sort(components[rootX].rbegin(), components[rootX].rend());
        if (components[rootX].size() > 10)
            components[rootX].resize(10);

        parent[rootY] = rootX;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            uf.unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            --v;

            int root = uf.find(v);
            if ((int)uf.components[root].size() >= k) {
                cout << uf.components[root][k - 1] + 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}