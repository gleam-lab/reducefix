#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)

struct UnionFind {
    vector<int> parent;
    vector<vector<int>> components;

    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        components.resize(n);
        for (int i = 0; i < n; ++i) {
            components[i].push_back(i);
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        // Always merge smaller component into larger one
        if (root_u == root_v) return;
        if (components[root_u].size() < components[root_v].size())
            swap(root_u, root_v);

        // Merge components[root_v] into components[root_u]
        components[root_u].insert(components[root_u].end(),
                                  components[root_v].begin(),
                                  components[root_v].end());
        components[root_v].clear();
        parent[root_v] = root_u;
    }

    vector<int>& get_component(int x) {
        int root = find(x);
        return components[root];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
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

            vector<int>& comp = uf.get_component(v);
            if ((int)comp.size() < k) {
                cout << -1 << '\n';
            } else {
                // Since we only need top 10 largest, keep them sorted descending
                static vector<int> buffer;
                buffer.assign(comp.begin(), comp.end());
                sort(buffer.rbegin(), buffer.rend());
                if ((int)buffer.size() >= k) {
                    cout << buffer[k - 1] + 1 << '\n'; // Convert 0-based to 1-based
                } else {
                    cout << -1 << '\n';
                }
            }
        }
    }

    return 0;
}