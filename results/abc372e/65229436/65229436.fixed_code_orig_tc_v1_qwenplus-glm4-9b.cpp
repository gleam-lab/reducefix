#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N + 1);
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < Q; i++) {
        int type, u, v, k;
        cin >> type;

        if (type == 1) {
            cin >> u >> v;
            uf.unite(u, v);
        } else {
            cin >> v >> k;
            set<int> component = graph[v];
            if (k > component.size()) {
                cout << "-1" << endl;
            } else {
                for (int elem : component) {
                    uf.unite(v, elem);
                }
                for (int elem : component) {
                    uf.unite(elem, v);
                }
                int counter = 0;
                for (int elem : component) {
                    if (uf.findRoot(elem) == uf.findRoot(v)) {
                        counter++;
                        if (counter == k) {
                            cout << elem << endl;
                            break;
                        }
                    }
                }
            }
        }
    }

    return 0;
}