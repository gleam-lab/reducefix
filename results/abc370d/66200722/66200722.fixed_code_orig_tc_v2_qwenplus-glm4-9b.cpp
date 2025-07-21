#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] > size[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            } else {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        }
    }
};

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    UnionFind uf(h * w);

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        // Process the query to destroy walls and update the union-find structure
    }

    // Calculate the number of remaining walls
    int remainingWalls = h * w; // Initially, all walls are present
    for (int i = 0; i < h * w; ++i) {
        if (uf.find(i) == i) {
            // Wall at index i is not part of any merged set, so it's still present
            remainingWalls--;
        }
    }

    cout << remainingWalls << endl;

    return 0;
}