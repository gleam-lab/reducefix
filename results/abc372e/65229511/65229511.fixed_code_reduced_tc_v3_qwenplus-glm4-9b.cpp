#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
using pli = pair<ll, int>;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

struct UnionFind {
    vector<int> parent, rank;
    vector<set<int>> group_size;

    UnionFind(int n) : parent(n), rank(n, 0), group_size(n, {}) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);
        if (rx == ry) return false;

        if (rank[rx] < rank[ry]) swap(rx, ry);

        for (int node : group_size[ry]) {
            group_size[rx].insert(node);
        }
        group_size[rx].insert(ry);
        group_size[ry].clear();

        parent[ry] = rx;
        if (rank[rx] == rank[ry]) {
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
            if (k > uf.group_size[v - 1].size()) {
                cout << -1 << '\n';
            } else {
                cout << *(upper_bound(uf.group_size[v - 1].rbegin(), uf.group_size[v - 1].rend(), v - 1) - 1) + 1 << '\n';
            }
        }
    }

    return 0;
}