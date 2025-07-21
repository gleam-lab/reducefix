#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find {
    vector<int> par;
    vector<vector<int>> top;

    Union_Find(int n) {
        par.resize(n, -1);
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
        x = root(x), y = root(y);
        if (x == y) return;
        if (top[x].size() < top[y].size()) swap(x, y);
        par[y] = x;
        top[x].insert(top[x].end(), top[y].begin(), top[y].end());
        sort(top[x].rbegin(), top[x].rend());
        if (top[x].size() > 10) top[x].resize(10);
        top[y].clear(); // optional, to save memory
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
            int root = uf.root(a);
            if (uf.top[root].size() < b + 1) {
                cout << -1 << '\n';
            } else {
                cout << uf.top[root][b] + 1 << '\n';
            }
        }
    }
}