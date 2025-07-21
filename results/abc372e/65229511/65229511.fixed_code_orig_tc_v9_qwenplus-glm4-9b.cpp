#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using pi = pair<int, int>;
const int INF = 1e9;

struct UnionFind {
    vector<int> parent, rank, size;

    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
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
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY];
            }
            return true;
        }
        return false;
    }

    int getSize(int x) {
        return size[findRoot(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = uf.findRoot(v);
            if (uf.getSize(root) < k) {
                cout << -1 << endl;
            } else {
                set<int> vertices;
                for (int i = 1; i <= N; ++i) {
                    if (uf.findRoot(i) == root) {
                        vertices.insert(i);
                    }
                }
                auto it = vertices.rbegin();
                advance(it, k - 1);
                cout << *it << endl;
            }
        }
    }

    return 0;
}