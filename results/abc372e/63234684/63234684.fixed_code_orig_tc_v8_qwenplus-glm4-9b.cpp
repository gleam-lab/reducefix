#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)

struct UnionFind {
    vector<int> par, rank, size;
    UnionFind(int n) {
        par.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int find(int u) {
        if (par[u] != u) par[u] = find(par[u]);
        return par[u];
    }
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        size[u] += size[v];
        par[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            uf.merge(u, v);
        } else if (type == 2) {
            v--;
            int root = uf.find(v);
            vector<int> component;
            for (int i = 0; i < n; i++) {
                if (uf.find(i) == root) component.push_back(i);
            }
            if (k > component.size()) {
                cout << -1 << endl;
            } else {
                cout << component[k - 1] + 1 << endl;
            }
        }
    }
    return 0;
}