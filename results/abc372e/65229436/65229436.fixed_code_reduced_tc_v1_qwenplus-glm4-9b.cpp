#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) 
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
    vector<int> componentsSize(n);
    iota(componentsSize.begin(), componentsSize.end(), 1); // Initialize each component with size 1

    vector<int> ans;
    rep(qi, q) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int root_u = uf.findRoot(u), root_v = uf.findRoot(v);
            if (root_u != root_v) {
                if (componentsSize[root_u] < componentsSize[root_v]) swap(root_u, root_v);
                uf.unite(root_u, root_v);
                componentsSize[root_v] += componentsSize[root_u];
                componentsSize[root_u] = 0;
            }
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root_v = uf.findRoot(v);
            if (k > componentsSize[root_v]) {
                ans.push_back(-1);
            } else {
                ans.push_back(v + 1);
                // Since we want the k-th largest, we need to find k-th smallest by descending order
                for (int i = 0; i < k; ++i) {
                    // Find the smallest element in the subtree
                    int elem = v + 1;
                    while (componentsSize[uf.findRoot(elem - 1)] < componentsSize[uf.findRoot(elem)]) {
                        elem = uf.findRoot(elem);
                    }
                    v = elem;
                }
                ans.push_back(v);
            }
        }
    }
    for (int x : ans) {
        cout << x << endl;
    }
    return 0;
}