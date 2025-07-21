#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

constexpr int MAXN = 200010;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        rank[u] += rank[v];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n + 1);
    vector<set<int>> adj(n + 1);

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 1) {
            uf.unite(u, v);
        } else {
            int root = uf.find(u);
            auto &s = adj[root];
            s.insert(-v);
            if (s.size() > 10) {
                s.erase(s.begin());
            }
            if (!s.empty()) {
                cout << -(*s.begin()) << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}