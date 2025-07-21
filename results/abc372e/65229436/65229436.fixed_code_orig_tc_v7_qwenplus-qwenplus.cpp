#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using pii = pair<int, int>;

struct UnionFind {
    vector<int> parent, rank;
    vector<multiset<int, greater<int>>> comps;

    UnionFind(int n) : parent(n), rank(n, 0), comps(n) {
        for (int i = 0; i < n; i++) {
            comps[i].insert(i);
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;

        // Merge smaller set into larger
        if (comps[rx].size() < comps[ry].size()) swap(rx, ry);

        for (int val : comps[ry]) {
            comps[rx].insert(val);
        }
        comps[ry].clear();
        parent[ry] = rx;
        return true;
    }

    multiset<int, greater<int>>& getComponent(int x) {
        return comps[findRoot(x)];
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
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            auto& comp = uf.getComponent(v);
            if (comp.size() < k) {
                ans.push_back(-1);
            } else {
                auto it = comp.begin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for (int x : ans) cout << x << "\n";

    return 0;
}