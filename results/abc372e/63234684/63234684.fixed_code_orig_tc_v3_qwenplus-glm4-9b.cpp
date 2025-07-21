#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<priority_queue<int, vector<int>, greater<int>>> components;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
            components.emplace_back();
            components.back().push(i);
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        int root = find(parent[x]);
        parent[x] = root;
        return root;
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                components[rootX].push(components[rootY].top());
                components[rootY].pop();
                if (components[rootX].size() > 10) {
                    components[rootX].pop();
                }
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                components[rootY].push(components[rootX].top());
                components[rootX].pop();
                if (components[rootY].size() > 10) {
                    components[rootY].pop();
                }
            } else {
                parent[rootY] = rootX;
                components[rootX].push(components[rootY].top());
                components[rootY].pop();
                if (components[rootX].size() > 10) {
                    components[rootX].pop();
                }
                rank[rootX] += 1;
            }
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            uf.unite(u - 1, v - 1);
        } else {
            int root = uf.find(v - 1);
            if (uf.components[root].size() < v) {
                cout << -1 << endl;
            } else {
                cout << uf.components[root].top() + 1 << endl;
                uf.components[root].pop();
                if (uf.components[root].size() > 10) {
                    uf.components[root].pop();
                }
            }
        }
    }
    return 0;
}