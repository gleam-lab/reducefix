#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) a.begin(), a.end()

using ll = long long;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<set<int>> groups(n);

    for (int i = 0; i < q; ++i) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (uf.unite(u, v)) {
                int rootV = uf.findRoot(v);
                groups[rootV].insert(v);
            }
        } else if (queryType == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int rootV = uf.findRoot(v);
            if (groups[rootV].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = groups[rootV].rbegin();
                std::advance(it, k - 1);
                cout << *(it) + 1 << endl;
            }
        }
    }

    return 0;
}