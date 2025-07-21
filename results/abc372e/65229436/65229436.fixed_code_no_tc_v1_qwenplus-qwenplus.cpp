#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent, rank, size;
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
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
            size[ry] += size[rx];
        } else {
            parent[ry] = rx;
            size[rx] += size[ry];
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<set<int>> component(n);
    rep(i, n) component[i].insert(i);

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru = uf.findRoot(u);
            int rv = uf.findRoot(v);
            if (ru != rv) {
                // Always merge smaller set into larger one
                if (component[ru].size() < component[rv].size()) swap(ru, rv);
                for (int x : component[rv]) {
                    component[ru].insert(x);
                    uf.parent[x] = ru; // Important: Update parent pointers
                }
                component[rv].clear();
                uf.parent[rv] = ru;
            }
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            if ((int)component[root].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = component[root].rbegin();
                advance(it, k-1);
                cout << (*it)+1 << endl;
            }
        }
    }

    return 0;
}