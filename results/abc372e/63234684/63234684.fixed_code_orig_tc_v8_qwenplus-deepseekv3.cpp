#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> par;
    vector<int> sz;
    vector<vector<int>> top;

    Union_Find(int n) {
        par.resize(n);
        sz.resize(n, 1);
        top.resize(n);
        rep(i, n) {
            par[i] = i;
            top[i].push_back(i);
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
        top[x].insert(top[x].end(), top[y].begin(), top[y].end());
        sort(top[x].rbegin(), top[x].rend());
        if (top[x].size() > 10) top[x].resize(10);
    }

    vector<int> get_top(int x) {
        x = root(x);
        return top[x];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
            vector<int> top = uf.get_top(a);
            if (top.size() < b + 1) {
                cout << -1 << '\n';
            } else {
                cout << top[b] + 1 << '\n';
            }
        }
    }
    return 0;
}