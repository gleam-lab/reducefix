#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<vector<int>> top;

    UnionFind(int n) : parent(n + 1), top(n + 1) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            top[i].push_back(i);
        }
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
        if (top[u].size() < top[v].size()) {
            swap(u, v);
        }
        vector<int> merged;
        int i = 0, j = 0;
        while (i < top[u].size() && j < top[v].size() && merged.size() < 10) {
            if (top[u][i] > top[v][j]) {
                merged.push_back(top[u][i++]);
            } else {
                merged.push_back(top[v][j++]);
            }
        }
        while (i < top[u].size() && merged.size() < 10) {
            merged.push_back(top[u][i++]);
        }
        while (j < top[v].size() && merged.size() < 10) {
            merged.push_back(top[v][j++]);
        }
        top[u] = merged;
        parent[v] = u;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);

    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uf.unite(a, b);
        } else {
            int root = uf.find(a);
            if (uf.top[root].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << uf.top[root][b - 1] << '\n';
            }
        }
    }

    return 0;
}