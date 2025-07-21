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
    vector<multiset<int, greater<int>>> vertices;
    UnionFind(int n) : parent(n), vertices(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            vertices[i].insert(i);
        }
    }
    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        int rx = findRoot(x);
        int ry = findRoot(y);
        if (rx == ry) return;
        if (vertices[rx].size() < vertices[ry].size()) {
            swap(rx, ry);
        }
        parent[ry] = rx;
        for (int v : vertices[ry]) {
            vertices[rx].insert(v);
        }
        vertices[ry].clear();
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
            if (uf.vertices[root].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = uf.vertices[root].begin();
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