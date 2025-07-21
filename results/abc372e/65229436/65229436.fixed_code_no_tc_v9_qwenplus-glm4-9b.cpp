#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
using ll = long long;

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<set<int>> components(n);
    rep(i, n) components[i].insert(i);
    vector<int> ans;
    while(q--) {
        int com;
        cin >> com;
        if(com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
            if (components[uf.findRoot(u)].size() < components[uf.findRoot(v)].size()) {
                swap(components[uf.findRoot(u)], components[uf.findRoot(v)]);
            }
            for (int x : components[uf.findRoot(v)]) {
                components[uf.findRoot(u)].insert(x);
            }
            components[uf.findRoot(v)].clear();
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            if (components[uf.findRoot(v)].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = components[uf.findRoot(v)].rbegin();
                advance(it, k - 1);
                ans.push_back(*it);
            }
        }
    }
    for (int x : ans) cout << x + 1 << endl;

    return 0;
}