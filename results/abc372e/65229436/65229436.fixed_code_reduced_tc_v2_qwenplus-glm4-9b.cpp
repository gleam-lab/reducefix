#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
using ll = long long;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) {
                rank[rx]++;
            }
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
    vector<vector<int>> edges(n);
    
    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            vector<int> components;
            for (int i = 0; i < n; i++) {
                if (uf.findRoot(i) == uf.findRoot(v)) {
                    components.push_back(i + 1);
                }
            }
            if (k > components.size()) {
                cout << -1 << endl;
            } else {
                cout << components[k - 1] << endl;
            }
        }
    }
    
    return 0;
}