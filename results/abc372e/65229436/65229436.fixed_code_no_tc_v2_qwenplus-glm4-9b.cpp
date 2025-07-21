#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
using ll = long long;

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findRoot(parent[x]);
    }

    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (size[x] < size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
        return true;
    }

    int getSize(int x) {
        return size[findRoot(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<vector<int>> adj(n);

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            int root = uf.findRoot(v - 1);
            if (k > adj[root].size()) {
                cout << -1 << endl;
            } else {
                cout << adj[root][adj[root].size() - k] + 1 << endl;
            }
        }
    }

    return 0;
}