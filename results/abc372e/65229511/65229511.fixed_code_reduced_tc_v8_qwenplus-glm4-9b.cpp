#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) a.begin(), a.end()

using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) 
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) 
                swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            return true;
        }
        return false;
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    vector<set<int>> graph(n);
    rep(i, n) graph[i].insert(i);

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.find(v);
            if (graph[root].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = graph[root].rbegin();
                advance(it, k - 1);
                cout << *it + 1 << '\n';
            }
        }
    }

    return 0;
}