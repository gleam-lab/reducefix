#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<vector<int>> edges; // Store edges for each component

    Union_Find(int n) {
        sz.resize(n + 1, 1);
        par.resize(n + 1, -1);
        edges.resize(n + 1);
    }

    int root(int v) {
        if (par[v] == -1) return v;
        return par[v] = root(par[v]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        edges[x].insert(edges[x].end(), edges[y].begin(), edges[y].end());
        edges[y].clear();
    }

    vector<int> get_connected_vertices(int v) {
        if (!issame(v, root(v))) return {};
        sort(edges[v].rbegin(), edges[v].rend());
        return edges[v];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);
    
    rep(i, q) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--, b--;
        if (ty == 1) {
            uf.merge(a, b);
        } else {
            auto connected = uf.get_connected_vertices(b);
            if (connected.size() <= b) {
                cout << -1 << endl;
            } else {
                cout << connected[b] << endl;
            }
        }
    }
}