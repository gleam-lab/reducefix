#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

struct DSU {
    vector<int> e;
    DSU(int n) { e = vector<int>(n, -1); }

    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    void unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    DSU dsu(n + 1);
    vector<vector<int>> adj(n + 1);

    rep(i, q) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            u--, v--;
            dsu.unite(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            cin >> u >> k;
            u--;
            int root = dsu.get(u);
            auto &list = adj[root];
            if (k > list.size()) {
                cout << -1 << endl;
            } else {
                sort(list.begin(), list.end());
                cout << list[list.size() - k] + 1 << endl;
            }
        }
    }

    return 0;
}