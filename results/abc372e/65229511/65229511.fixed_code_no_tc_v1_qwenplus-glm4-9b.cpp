#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
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
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    ll n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<vector<int>> graph(n);
    while (q--) {
        ll com;
        cin >> com;
        if (com == 1) {
            ll u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else {
            ll v, k;
            cin >> v >> k;
            ll root = uf.findRoot(v - 1);
            vector<int> nodes;
            for (auto neighbor : graph[root]) {
                nodes.push_back(neighbor);
            }
            nodes.push_back(root);
            if (nodes.size() < k) {
                cout << -1 << endl;
            } else {
                sort(nodes.begin(), nodes.end(), greater<int>());
                cout << nodes[k - 1] + 1 << endl;
            }
        }
    }
    return 0;
}