#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<vector<int>> uni;

    Union_Find(int n) {
        sz.resize(n, 1);
        par.resize(n, -1);
        uni.resize(n);
        for (int i = 0; i < n; ++i) uni[i].push_back(i);
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
        // Always merge smaller set into larger one
        if (uni[x].size() < uni[y].size()) swap(x, y);
        // Move all elements from y to x
        uni[x].insert(uni[x].end(), uni[y].begin(), uni[y].end());
        uni[y].clear();
        sz[x] += sz[y];
        sz[y] = 0;
        par[y] = x;
        // Sort and keep only top 10 largest elements
        sort(uni[x].rbegin(), uni[x].rend());
        while (uni[x].size() > 10) {
            uni[x].pop_back();
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
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
            int rt = uf.root(a);
            if ((int)uf.uni[rt].size() <= b) {
                cout << -1 << "\n";
            } else {
                cout << uf.uni[rt][b] + 1 << "\n";
            }
        }
    }

    return 0;
}