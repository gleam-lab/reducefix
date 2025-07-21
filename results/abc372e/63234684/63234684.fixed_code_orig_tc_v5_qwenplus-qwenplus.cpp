#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<vector<int>> top_k;

    Union_Find(int n) {
        sz.resize(n, 1);
        par.resize(n, -1);
        top_k.resize(n);
        for (int i = 0; i < n; ++i)
            top_k[i].push_back(i);
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
        sz[x] += sz[y];
        sz[y] = 0;
        par[y] = x;

        // Merge the top_k lists and keep top 10 elements
        for (int val : top_k[y])
            top_k[x].push_back(val);
        top_k[y].clear();

        // Sort in descending order and keep top 10
        sort(top_k[x].begin(), top_k[x].end(), greater<int>());
        if (top_k[x].size() > 10)
            top_k[x].resize(10);
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
        a--, b--;
        if (ty == 1) {
            uf.merge(a, b);
        } else {
            int r = uf.root(a);
            if ((int)uf.top_k[r].size() <= b) {
                cout << -1 << "\n";
            } else {
                cout << uf.top_k[r][b] + 1 << "\n";
            }
        }
    }

    return 0;
}