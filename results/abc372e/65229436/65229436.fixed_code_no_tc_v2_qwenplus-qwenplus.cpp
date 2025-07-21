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
    UnionFind(int n) : parent(n) {
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
        parent[ry] = rx;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<set<int>> components(n);
    for (int i = 0; i < n; ++i)
        components[i].insert(i);

    vector<int> ans;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru = uf.findRoot(u);
            int rv = uf.findRoot(v);
            if (ru != rv) {
                // Always merge smaller set into larger to optimize performance
                if (components[ru].size() < components[rv].size()) {
                    swap(ru, rv);
                    swap(u, v); // Not strictly necessary, just keeps u/v matching root
                }
                for (int node : components[rv]) {
                    components[ru].insert(node);
                    uf.parent[node] = ru;
                }
                components[rv].clear();
            }
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            if ((int)components[root].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = components[root].rbegin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for (auto x : ans)
        cout << x << endl;

    return 0;
}