#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<vector<int>> uni;

    Union_Find(int n) {
        sz.resize(n + 1, 1);
        par.resize(n + 1, -1);
        uni.resize(n + 1);
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
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        sz[y] = 0;
        par[y] = x;
        while (!uni[y].empty()) {
            uni[x].emplace_back(uni[y].back());
            uni[y].pop_back();
        }
        sort(uni[x].rbegin(), uni[x].rend());
        while (uni[x].size() > 9) uni[x].pop_back();
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);

    while (q--) {
        int ty, v, k;
        cin >> ty >> v >> k;
        v--; // Convert to zero-indexed for easier array manipulation
        if (ty == 1) {
            int u = k;
            k = v;
            v = u;
            uf.merge(v, k);
        } else {
            if (!uf.issame(v, 1)) { // If v is not connected to vertex 1
                cout << -1 << endl;
                continue;
            }
            if (uf.uni[v].size() < k) {
                cout << -1 << endl;
            } else {
                cout << uf.uni[v][k - 1] + 1 << endl; // Convert to one-indexed for output
            }
        }
    }
}