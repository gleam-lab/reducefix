#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> par, sz;
    vector<vector<int>> top;

    Union_Find(int n) {
        par.resize(n, -1);
        sz.resize(n, 1);
        top.resize(n);
        rep(i, n) top[i].push_back(i);
    }

    int root(int v) {
        if (par[v] == -1) return v;
        return par[v] = root(par[v]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        top[x].insert(top[x].end(), top[y].begin(), top[y].end());
        sort(top[x].rbegin(), top[x].rend());
        if (top[x].size() > 10) top[x].resize(10);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    Union_Find uf(N);

    rep(i, Q) {
        int ty, u, v;
        cin >> ty >> u >> v;
        u--; v--;
        if (ty == 1) {
            uf.merge(u, v);
        } else {
            int r = uf.root(u);
            if (uf.top[r].size() < v + 1) {
                cout << -1 << '\n';
            } else {
                cout << uf.top[r][v] + 1 << '\n';
            }
        }
    }
}