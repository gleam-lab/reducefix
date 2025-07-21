#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent;
    vector<set<int>> components;

    UnionFind(int n) : parent(n) {
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

    void unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return;

        // Always merge smaller set into larger one
        if (components[rx].size() < components[ry].size()) {
            swap(rx, ry);
        }

        // Merge ry's component into rx's component
        parent[ry] = rx;
        components[rx].merge(components[ry]);
    }

    const set<int>& getComponent(int x) {
        return components[findRoot(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<long long> ans;

    rep(qi, q) {
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

            const auto& comp = uf.getComponent(v);
            if ((int)comp.size() < k) {
                ans.pb(-1);
            } else {
                auto it = comp.rbegin();
                advance(it, k - 1);
                ans.pb(*it + 1);
            }
        }
    }

    for (auto x : ans) cout << x << endl;

    return 0;
}