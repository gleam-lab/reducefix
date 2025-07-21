#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
#define all(x) begin(x),end(x)

struct UnionFind {
    vector<int> par, rank, size;
    UnionFind(int n) : par(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }
    
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    void merge(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) {
                swap(rx, ry);
            }
            if (rank[rx] == rank[ry]) ++rank[rx];
            par[ry] = rx;
            size[rx] += size[ry];
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    
    rep(i, q) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            uf.merge(a - 1, b - 1);
        } else {
            int v = a - 1;
            int rootV = uf.root(v);
            vector<int> component;
            for (int i = 0; i < n; ++i) {
                if (uf.root(i) == rootV) {
                    component.push_back(i + 1);
                }
            }
            sort(all(component));
            if (b > component.size()) {
                cout << -1 << endl;
            } else {
                cout << component[component.size() - b] << endl;
            }
        }
    }
}