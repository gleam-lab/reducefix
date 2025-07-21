#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    int components;

    UnionFind(int n) : parent(n), rank(n), components(n) {
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
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            components--;
            return true;
        }
        return false;
    }

    int size(int x) {
        return components - count_if(parent.begin(), parent.end(), [&](int root) {
            return findRoot(root) == x;
        });
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<set<int>> adj(n);
    vector<int> results;

    for (int i = 0; i < q; ++i) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u - 1, v - 1);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            set<int> neighbors = adj[v];
            if (uf.size(v) < k) {
                results.push_back(-1);
            } else {
                auto it = neighbors.begin();
                for (int i = 0; i < k - 1; ++i) {
                    ++it;
                }
                results.push_back(*it + 1);
            }
        }
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}