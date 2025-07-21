#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
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
    vector<int> vertexDegrees(n + 1, 0);
    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {  // Add edge
            uf.unite(u, v);
        } else {  // Query k-th largest
            cin >> k;
            int root = uf.find(v);
            vector<int> connectedVertices = adjList[root];
            sort(connectedVertices.begin(), connectedVertices.end(), greater<int>());
            if (k > connectedVertices.size()) {
                cout << -1 << endl;
            } else {
                cout << connectedVertices[k - 1] << endl;
            }
        }
    }

    return 0;
}