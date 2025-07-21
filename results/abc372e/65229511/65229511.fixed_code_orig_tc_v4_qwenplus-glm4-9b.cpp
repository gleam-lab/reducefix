#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;

struct UnionFind {
    vector<int> parent, rank, size;

    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }

    int findRoot(int x) {
        if (parent[x] != x) 
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = findRoot(x);
        int rootY = findRoot(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
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

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    while (q--) {
        int com;
        cin >> com;

        if (com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            int rootV = uf.findRoot(v - 1);
            if (uf.getSize(rootV) < k) {
                cout << -1 << endl;
            } else {
                // Add the vertices to a vector
                vector<int> vertices;
                for (int i = 0; i < n && vertices.size() < k; i++) {
                    if (uf.findRoot(i) == rootV) {
                        vertices.push_back(i + 1);
                    }
                }

                // Output the k-th largest vertex
                cout << vertices[vertices.size() - k] << endl;
            }
        }
    }

    return 0;
}