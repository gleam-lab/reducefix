#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define all(a) a.begin(), a.end()
using ll = long long;
using pi = pair<int, int>;

const int INF = 1e9;
const int MAX_N = 2e5 + 10;

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
        int rx = findRoot(x);
        int ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry])
            swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry])
            rank[rx]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    map<int, vector<int>> adj;
    rep(i, q) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            auto &vec = adj[root];
            if (int(vec.size()) < k)
                cout << -1 << '\n';
            else
                cout << vec[k - 1] + 1 << '\n';
        }
    }
    return 0;
}