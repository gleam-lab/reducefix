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
        sz.resize(n, 1);
        par.resize(n, -1);
        uni.resize(n);
        for (int i = 0; i < n; i++) uni[i].emplace_back(i);
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
        if (y > x) swap(x, y);
        if (x == y) return;
        sz[x] += sz[y];
        sz[y] = 0;
        par[y] = x;
        while (!uni[y].empty()) {
            int elem = uni[y].back();
            uni[y].pop_back();
            uni[x].emplace_back(elem);
        }
        // Maintain the size of uni[x] to be at most 10
        while (uni[x].size() > 10) uni[x].pop_back();
    }
};

int main() {
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
            if (uf.uni[uf.root(a)].size() <= b) {
                cout << -1 << endl;
            } else {
                cout << uf.uni[uf.root(a)][b] + 1 << endl;
            }
        }
    }
}