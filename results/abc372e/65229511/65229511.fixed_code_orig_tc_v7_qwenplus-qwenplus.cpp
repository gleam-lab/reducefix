#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<int, int> pi;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<set<int>> components;

    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i].insert(i);
        }
    }

    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);

        if (rx == ry) return;

        // Always merge smaller into larger
        if (components[rx].size() < components[ry].size())
            swap(rx, ry);

        // Merge ry into rx
        for (int val : components[ry])
            components[rx].insert(val);
        components[ry].clear();
        parent[ry] = rx;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    vector<int> ans;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = uf.findRoot(v - 1);
            if (uf.components[root].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = uf.components[root].rbegin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for (int x : ans)
        cout << x << '\n';

    return 0;
}