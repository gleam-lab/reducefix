#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0;i<(n);i++)
using ll = long long;
using pii = pair<int, int>;

struct UnionFind {
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (size[rx] < size[ry]) swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    vector<set<int>> components(N);
    rep(i, N) components[i].insert(i);

    vector<int> ans;

    rep(_, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru = uf.find(u), rv = uf.find(v);
            if (ru != rv) {
                if (components[ru].size() < components[rv].size()) {
                    swap(ru, rv);
                }
                // merge rv into ru
                for (int x : components[rv]) {
                    components[ru].insert(x);
                }
                components[rv].clear();
                uf.unite(ru, rv);
            }
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.find(v);
            if (components[root].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = components[root].rbegin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for (int x : ans) cout << x << "\n";

    return 0;
}