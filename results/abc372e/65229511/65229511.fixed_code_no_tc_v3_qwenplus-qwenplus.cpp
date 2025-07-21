#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent;
    vector<set<int>> components;

    UnionFind(int n) : parent(n), components(n) {
        for (int i = 0; i < n; ++i) {
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

        // Always merge smaller into larger for efficiency
        if (components[rx].size() < components[ry].size())
            swap(rx, ry);

        // Merge component ry into rx
        for (int node : components[ry])
            components[rx].insert(node);

        parent[ry] = rx;
        components[ry].clear(); // Clear the old component
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<long long> answers;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            auto& comp = uf.components[uf.findRoot(v - 1)];
            if (comp.size() < static_cast<size_t>(k)) {
                answers.push_back(-1);
            } else {
                auto it = comp.rbegin();
                advance(it, k - 1);
                answers.push_back(*it + 1);
            }
        }
    }

    for (auto ans : answers)
        cout << ans << "\n";

    return 0;
}