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
        rep(i, n) {
            top[i].push_back(i);
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
        if (top[x].size() < top[y].size()) swap(x, y);
        vector<int> merged;
        merge(top[x].begin(), top[x].end(), top[y].begin(), top[y].end(), back_inserter(merged), greater<int>());
        if (merged.size() > 10) merged.resize(10);
        top[x] = merged;
        par[y] = x;
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
            int root_a = uf.root(a);
            if (uf.top[root_a].size() < b + 1) {
                cout << -1 << '\n';
            } else {
                cout << uf.top[root_a][b] + 1 << '\n';
            }
        }
    }
}