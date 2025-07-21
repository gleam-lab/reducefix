#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find {
    vector<int> par;
    vector<vector<int>> uni;

    Union_Find(int n) {
        par.resize(n, -1);
        uni.resize(n);
        rep(i, n) uni[i].push_back(i);
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
        if (uni[x].size() < uni[y].size()) swap(x, y);
        par[y] = x;
        uni[x].insert(uni[x].end(), uni[y].begin(), uni[y].end());
        uni[y].clear();
        sort(uni[x].rbegin(), uni[x].rend());
        if (uni[x].size() > 10) uni[x].resize(10);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
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
            int root = uf.root(a);
            if (uf.uni[root].size() <= b) {
                cout << -1 << '\n';
            } else {
                cout << uf.uni[root][b] + 1 << '\n';
            }
        }
    }
}