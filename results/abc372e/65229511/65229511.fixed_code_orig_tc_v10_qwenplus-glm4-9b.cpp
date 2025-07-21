#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using pi = pair<int, int>;

const int INF = 1e9;

struct UnionFind {
    vector<int> parent, rank, size;
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        if (rank[rx] == rank[ry]) rank[rx]++;
        parent[ry] = rx;
        size[rx] += size[ry];
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
    vector<vector<int>> graph(n);
    rep(i, n) graph[i].push_back(i);
    
    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = uf.findRoot(v);
            if (k > graph[root].size()) {
                cout << -1 << endl;
            } else {
                cout << graph[root][k - 1] + 1 << endl;
            }
        }
    }
    return 0;
}