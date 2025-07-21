#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n) : parent(n+1), size(n+1, 1) {
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) {
            return false;
        }
        if(size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        return true;
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<vector<int>> component;
    vector<map<int, int>> rank; // to keep track of the frequency of each vertex in the component

    for(int i = 0; i < q; i++) {
        int op, u, v;
        cin >> op >> u >> v;

        if(op == 1) {
            if(uf.find(u) != uf.find(v)) {
                uf.unite(u, v);
            }
        } else if(op == 2) {
            int root = uf.find(v);
            if(rank[root].size() < v) {
                cout << "-1" << endl;
            } else {
                cout << rank[root][v] << endl;
            }
        }
    }

    return 0;
}