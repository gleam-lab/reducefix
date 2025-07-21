#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};
const int INF = 1e9;
struct UnionFind {
    vector<int> parent, rank;
    vector<set<int>> vertices;
    UnionFind(int n) : parent(n), rank(n, 0), vertices(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            vertices[i].insert(i);
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
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
            for (int v : vertices[rx]) 
                vertices[ry].insert(v);
            vertices[rx].clear();
        } else {
            parent[ry] = rx;
            for (int v : vertices[ry]) 
                vertices[rx].insert(v);
            vertices[ry].clear();
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
        return true;
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
                auto it = uf.vertices[root].end();
                advance(it, -k);
                ans.push_back(*it + 1);
            }
        }
    }
    for (auto x : ans) 
        cout << x << endl;
    return 0;
}