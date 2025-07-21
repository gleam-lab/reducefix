#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    // Each root stores the set of nodes in its component
    vector<set<int>> components(n);
    for (int i = 0; i < n; ++i)
        components[i].insert(i);

    vector<int> ans;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru = uf.find(u);
            int rv = uf.find(v);
            if (ru != rv) {
                // Always merge smaller into larger
                if (components[ru].size() < components[rv].size()) {
                    swap(ru, rv);
                }
                // Merge rv into ru
                for (int node : components[rv]) {
                    components[ru].insert(node);
                }
                components[rv].clear();
                uf.unite(ru, rv);
            }
        } else if (t == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.find(v);
            const auto& comp = components[root];
            if ((int)comp.size() < k) {
                ans.push_back(-1);
            } else {
                auto it = comp.rbegin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for (int x : ans)
        cout << x << '\n';

    return 0;
}