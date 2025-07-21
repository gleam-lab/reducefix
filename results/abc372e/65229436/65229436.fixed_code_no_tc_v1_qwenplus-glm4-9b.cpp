#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
const int INF=1e9;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n, -1) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] < 0) return x;
        else return parent[x] = findRoot(parent[x]);
    }
    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        parent[x] = y;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<vector<int>> adj(n);
    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            vector<int> nodes;
            for (int i = 0; i < n; i++) {
                if (uf.findRoot(i) == root) {
                    nodes.push_back(i + 1); // Store 1-based index
                }
            }
            if (nodes.size() < k) {
                cout << "-1\n";
            } else {
                cout << nodes[k - 1] << "\n";
            }
        }
    }
    return 0;
}