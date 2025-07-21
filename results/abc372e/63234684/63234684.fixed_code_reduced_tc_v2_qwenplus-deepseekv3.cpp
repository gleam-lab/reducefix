#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> par, sz;
    vector<vector<int>> vertices;

    Union_Find(int n) {
        par.resize(n);
        sz.resize(n, 1);
        vertices.resize(n);
        rep(i, n) {
            par[i] = i;
            vertices[i].push_back(i);
        }
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        vertices[x].insert(vertices[x].end(), vertices[y].begin(), vertices[y].end());
        sort(vertices[x].rbegin(), vertices[x].rend());
        if (vertices[x].size() > 10) vertices[x].resize(10);
        vertices[y].clear();
    }

    int query(int x, int k) {
        x = root(x);
        if (vertices[x].size() < k) return -1;
        return vertices[x][k - 1] + 1; // +1 because vertices are 0-based in code but 1-based in input
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    Union_Find uf(N);

    while (Q--) {
        int type, u, v;
        cin >> type >> u >> v;
        u--, v--;
        if (type == 1) {
            uf.merge(u, v);
        } else {
            int res = uf.query(u, v);
            cout << res << '\n';
        }
    }

    return 0;
}