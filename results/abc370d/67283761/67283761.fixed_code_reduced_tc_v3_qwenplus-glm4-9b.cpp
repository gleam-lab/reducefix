#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 4 * 100000;

// Union-Find structure to keep track of connected components
struct UnionFind {
    int parent[MAXN];
    int rank[MAXN];
    int size[MAXN];

    void initialize() {
        fill(parent, parent + MAXN, -1);
    }

    int find(int u) {
        if (parent[u] == -1) return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (rank[u] < rank[v]) swap(u, v);
        if (rank[u] == rank[v]) rank[u]++;
        parent[v] = u;
        size[u] += size[v];
        return true;
    }

    int getSize(int u) {
        return size[find(u)];
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    UnionFind uf;
    uf.initialize();

    // Union all vertical walls
    for (int i = 0; i < H; i++) {
        uf.unite(i, i + H);
    }

    // Union all horizontal walls
    for (int i = 0; i < W; i++) {
        uf.unite(i, i + W);
    }

    // Process each query
    while (Q--) {
        int R, C;
        cin >> R >> C;

        // If the bomb destroys a wall at (R, C)
        if (uf.find(R - 1) != uf.find(C - 1)) {
            uf.unite(R - 1, C - 1);
        }
    }

    // Calculate the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (uf.find(i) == uf.find(j + H)) {
                // If the component containing (i, j) is connected to (i, j + H)
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}