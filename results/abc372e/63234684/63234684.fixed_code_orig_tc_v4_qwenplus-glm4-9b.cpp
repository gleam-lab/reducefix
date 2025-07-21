#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<vector<int>> components;

    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            components.emplace_back();
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        int root = find(parent[x]);
        parent[x] = root;
        return root;
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                components[rootX].push_back(x);
                components[rootX].push_back(y);
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                components[rootY].push_back(x);
                components[rootY].push_back(y);
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                components[rootX].push_back(x);
                components[rootX].push_back(y);
            }
        }
    }

    void sort_components() {
        for (auto &comp : components) {
            sort(comp.begin(), comp.end());
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            uf.merge(u, v);
        } else if (type == 2) {
            uf.find(u); // Find and path compression
            vector<int> &comp = uf.components[uf.find(u)];
            sort(uf.components[uf.find(u)], uf.components[uf.find(u)].end()); // Sort the component
            if (k > 0 && k <= comp.size()) {
                cout << comp.back() << '\n'; // Output k-th largest element
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}