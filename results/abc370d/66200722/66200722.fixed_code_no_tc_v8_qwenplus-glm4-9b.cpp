#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
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

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    UnionFind uf(H * W);
    vector<vector<set<int>>> grid(H, vector<set<int>>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            grid[i][j].insert(i * W + j);
        }
    }

    for (int q = 0; q < Q; q++) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        auto destroyWalls = [&](int r, int c) {
            auto& cells = grid[r][c];
            for (int x : cells) {
                uf.unite(x, r * W + c);
            }
        };

        // Destroy the wall at (R, C)
        if (!grid[R][C].empty()) {
            int wallId = *grid[R][C].begin();
            uf.unite(wallId, R * W + C);
            grid[R][C].erase(grid[R][C].begin());
        } else {
            // Destroy walls in all four directions
            destroyWalls(R, C);
            destroyWalls(R, C - 1);
            destroyWalls(R, C + 1);
            destroyWalls(R - 1, C);
            destroyWalls(R + 1, C);
        }
    }

    // Count the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            remainingWalls += grid[i][j].size();
        }
    }

    cout << remainingWalls << endl;

    return 0;
}