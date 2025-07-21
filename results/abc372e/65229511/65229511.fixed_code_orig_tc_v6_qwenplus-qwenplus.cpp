#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<set<int>> components;

    UnionFind(int n) {
        parent.resize(n);
        components.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i].insert(i);
        }
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return;

        // Always merge smaller into bigger
        if (components[rootU].size() < components[rootV].size()) {
            swap(rootU, rootV);
        }

        // Merge the smaller set into the larger one
        for (int val : components[rootV]) {
            components[rootU].insert(val);
        }
        components[rootV].clear();
        parent[rootV] = rootU;
    }

    const set<int>& getComponent(int x) {
        return components[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    vector<int> answers;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            uf.unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            --v;
            const set<int>& comp = uf.getComponent(v);
            if ((int)comp.size() < k) {
                answers.push_back(-1);
            } else {
                auto it = comp.rbegin();
                advance(it, k - 1);
                answers.push_back(*it + 1); // Convert back to 1-based index
            }
        }
    }

    for (int ans : answers) {
        cout << ans << '\n';
    }

    return 0;
}