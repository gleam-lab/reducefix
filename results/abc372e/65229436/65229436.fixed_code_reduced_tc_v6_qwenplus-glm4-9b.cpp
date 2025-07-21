#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] != x) parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n + 1); // Adjusted for 1-based index
    vector<vector<int>> adj(n + 1);
    vector<int> ans;

    for (int qi = 0; qi < q; ++qi) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v--; // Adjust for 0-based index
            int root = uf.findRoot(v);
            if (k > adj[root].size()) {
                ans.push_back(-1);
            } else {
                ans.push_back(adj[root][adj[root].size() - k]);
            }
        }
    }

    for (int x : ans) {
        cout << x + 1 << '\n'; // Adjust for 1-based index
    }

    return 0;
}