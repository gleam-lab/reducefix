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
        for (int i = 0; i < n; ++i) {
            top_k[i].push_back(i);
        }
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
        // Ensure x is larger (or equal) set to merge into
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;

        // Merge the top_k lists and keep top 10 largest elements
        vector<int> merged;
        int i = 0, j = 0;
        while (i < (int)top_k[x].size() && j < (int)top_k[y].size() && merged.size() < 10) {
            if (top_k[x][i] > top_k[y][j]) {
                merged.push_back(top_k[x][i++]);
            } else {
                merged.push_back(top_k[y][j++]);
            }
        }
        while (i < (int)top_k[x].size() && merged.size() < 10) {
            merged.push_back(top_k[x][i++]);
        }
        while (j < (int)top_k[y].size() && merged.size() < 10) {
            merged.push_back(top_k[y][j++]);
        }
        top_k[x] = merged;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    Union_Find uf(n);

    for (int i = 0; i < q; ++i) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--, b--;
        if (ty == 1) {
            uf.merge(a, b);
        } else {
            int r = uf.root(a);
            if ((int)uf.top_k[r].size() <= b) {
                cout << -1 << endl;
            } else {
                cout << uf.top_k[r][b] + 1 << endl;
            }
        }
    }

    return 0;
}