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
        // Ensure x has larger component
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;

        // Merge the top vertices, keep only top 10 largest
        for (int v : top_vertices[y])
            top_vertices[x].push_back(v);
        sort(top_vertices[x].rbegin(), top_vertices[x].rend());
        while (top_vertices[x].size() > 10)
            top_vertices[x].pop_back();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    Union_Find uf(N);

    for (int i = 0; i < Q; ++i) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--; b--;
        if (ty == 1) {
            uf.merge(a, b);
        } else {
            int r = uf.root(a);
            if (uf.top_vertices[r].size() <= b)
                cout << -1 << '\n';
            else
                cout << uf.top_vertices[r][b] + 1 << '\n';
        }
    }
}