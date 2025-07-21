#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<multiset<int, greater<int>>> components;

    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        for (int i = 0; i < n; i++) {
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

        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
            for (int v : components[rx]) {
                components[ry].insert(v);
            }
            components[rx].clear();
        } else {
            parent[ry] = rx;
            for (int v : components[ry]) {
                components[rx].insert(v);
            }
            components[ry].clear();
            if (rank[rx] == rank[ry]) {
                rank[rx]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<int> ans;

    rep(qi, q) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            if (uf.components[root].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = uf.components[root].begin();
                advance(it, k - 1);
                ans.push_back(*it + 1);
            }
        }
    }

    for (auto x : ans) {
        cout << x << endl;
    }

    return 0;
}