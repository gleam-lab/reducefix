#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
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
    vector<set<int>> component(n);
    for (int i = 0; i < n; ++i) {
        component[i].insert(i);
    }

    vector<string> ans;

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
                // Always merge smaller into larger
                if (component[ru].size() < component[rv].size()) {
                    swap(ru, rv);
                }
                uf.parent[rv] = ru;
                // Merge the sets
                component[ru].insert(component[rv].begin(), component[rv].end());
                component[rv].clear();
            }
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            if ((int)component[root].size() < k) {
                ans.push_back("-1");
            } else {
                auto it = component[root].rbegin();
                advance(it, k - 1);
                ans.push_back(to_string(*it + 1));
            }
        }
    }

    cout << join(ans.begin(), ans.end(), "\n");

    return 0;
}