#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> sz, par;
    vector<vector<int>> top10;

    Union_Find(int n) {
        sz.resize(n, 1);
        par.resize(n, -1);
        top10.resize(n);
        for (int i = 0; i < n; ++i)
            top10[i].push_back(i);
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

        // Ensure x > y to merge smaller into larger
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;

        // Merge the top lists and keep top 10 largest
        for (int val : top10[y])
            top10[x].push_back(val);

        // Sort in descending order and keep only top 10
        sort(top10[x].rbegin(), top10[x].rend());
        if (top10[x].size() > 10)
            top10[x].resize(10);

        sz[y] = 0;
        top10[y].clear();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    Union_Find uf(N);

    while (Q--) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--, b--;

        if (ty == 1) {
            uf.merge(a, b);
        } else {
            int r = uf.root(a);
            if ((int)uf.top10[r].size() <= b)
                cout << -1 << '\n';
            else
                cout << uf.top10[r][b] + 1 << '\n';
        }
    }

    return 0;
}