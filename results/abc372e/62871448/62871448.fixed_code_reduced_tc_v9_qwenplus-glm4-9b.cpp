#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) : parent(size + 1), rank(size + 1, 0) {
        for (int i = 0; i <= size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for (int i = 0; i < Q; i++) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            uf.unite(u, v);
        } else {
            int rootV = uf.find(v);
            set<int> connected;
            for (int j = 1; j <= N; j++) {
                if (uf.find(j) == rootV) {
                    connected.insert(j);
                }
            }

            if (k <= connected.size()) {
                cout << *prev(connected.end()) << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}