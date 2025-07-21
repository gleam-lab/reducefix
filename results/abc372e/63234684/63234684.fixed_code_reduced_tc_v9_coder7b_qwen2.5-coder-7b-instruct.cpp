#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find {
    vector<int> sz, par;
    map<int, set<int>> uni;

    Union_Find(int n) {
        sz.resize(n, 1);
        par.resize(n, -1);
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
        par[y] = x;
        uni[x].insert(uni[y].begin(), uni[y].end());
        uni.erase(y);
    }

    int kth_largest(int x, int k) {
        auto it = uni[root(x)].upper_bound(k);
        if (it == begin(uni[root(x)])) return -1;
        --it;
        return *it;
    }
};

int main() {
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
            cout << uf.kth_largest(b, 10 - k) << '\n';
        }
    }

    return 0;
}