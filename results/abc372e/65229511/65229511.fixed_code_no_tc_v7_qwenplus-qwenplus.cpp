#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using ll = long long;
using pi = pair<int, int>;

const int INF = 1e9;

struct UnionFind {
    vector<int> parent, rank;
    vector<set<int>> components;

    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            components[i].insert(i);
        }
    }

    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;

        // Always merge smaller set into larger one
        if (components[rx].size() < components[ry].size())
            swap(rx, ry);

        // Merge components
        components[rx].merge(components[ry]);

        // Update parent relationship
        parent[ry] = rx;

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    vector<string> ans;

    rep(_, q) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;

            auto root = uf.findRoot(v);
            auto& component = uf.components[root];

            if (component.size() < (size_t)k) {
                ans.push_back("-1");
            } else {
                // We need the k-th largest -> reverse iterator with advance
                auto it = component.rbegin();
                advance(it, k - 1);
                ans.push_back(to_string(*it + 1));
            }
        }
    }

    for (auto& s : ans)
        cout << s << "\n";

    return 0;
}