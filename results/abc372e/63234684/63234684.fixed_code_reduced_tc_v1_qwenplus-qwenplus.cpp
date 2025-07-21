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
        // Ensure x > y to always absorb into larger root
        if (y > x) swap(x, y);
        // Merge smaller set into larger one
        for (int val : top_k[y]) {
            top_k[x].push_back(val);
        }
        // Sort and keep only top 10 largest elements
        sort(top_k[x].rbegin(), top_k[x].rend());
        if (top_k[x].size() > 10)
            top_k[x].resize(10);
        sz[x] += sz[y];
        par[y] = x;
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
        a--;
        if (ty == 1) {
            uf.merge(a, b - 1);
        } else {
            int rt = uf.root(a);
            if (uf.top_k[rt].size() <= b) {
                cout << -1 << "\n";
            } else {
                cout << uf.top_k[rt][b] + 1 << "\n"; // convert 0-based to 1-based
            }
        }
    }
}