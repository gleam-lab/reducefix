#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<vector<int>> top_vertices;

    Union_Find(int n) {
        sz.resize(n, 1);
        par.resize(n, -1);
        top_vertices.resize(n);
        for (int i = 0; i < n; ++i)
            top_vertices[i].push_back(i);
    }

    int root(int v) {
        if (par[v] == -1) return v;
        else return par[v] = root(par[v]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        
        // Always merge smaller into larger
        if (sz[x] < sz[y]) swap(x, y);
        
        // Merge y's top vertices into x's list
        for (int v : top_vertices[y]) {
            top_vertices[x].push_back(v);
        }
        
        // Sort and keep only top 10 largest
        sort(top_vertices[x].rbegin(), top_vertices[x].rend());
        if (top_vertices[x].size() > 10)
            top_vertices[x].resize(10);

        sz[x] += sz[y];
        sz[y] = 0;
        par[y] = x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);

    while (q--) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--;  // Convert to 0-based index

        if (ty == 1) {
            uf.merge(a, b);
        } else {  // ty == 2
            int r = uf.root(a);
            if (b >= uf.top_vertices[r].size()) {
                cout << -1 << '\n';
            } else {
                cout << uf.top_vertices[r][b] + 1 << '\n';  // Convert back to 1-based
            }
        }
    }

    return 0;
}