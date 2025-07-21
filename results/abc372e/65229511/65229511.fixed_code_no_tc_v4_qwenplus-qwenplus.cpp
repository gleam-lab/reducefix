#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent, rank, size;
    vector<set<int>>* components;
    
    UnionFind(int n, vector<set<int>>* comp) : parent(n), rank(n, 0), size(n, 1), components(comp) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }

    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;

        if (components->at(rx).size() < components->at(ry).size()) {
            swap(rx, ry);
        }

        // Merge smaller component into larger one
        for (int node : components->at(ry)) {
            components->at(rx).insert(node);
            parent[node] = rx;
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    // Each component stores the vertices in sorted order
    vector<set<int>> components(n);
    for (int i = 0; i < n; ++i) {
        components[i].insert(i);
    }

    UnionFind uf(n, &components);

    vector<int> ans;

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

            int root = uf.findRoot(v);
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

    for (auto x : ans) cout << x << endl;

    return 0;
}