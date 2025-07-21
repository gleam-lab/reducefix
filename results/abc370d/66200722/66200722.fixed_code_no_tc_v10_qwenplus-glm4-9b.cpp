#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

struct UnionFind {
    vector<int> parent;
    vector<int> rank;

    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w, 1)); // 1 represents a wall
    UnionFind uf(h * w);

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        if (grid[r][c] == 1) { // Bomb destroys the wall at (r, c)
            grid[r][c] = 0;
        } else { // Bomb destroys the first wall in each direction
            // Up
            for (int i = r - 1; i >= 0 && grid[i][c] == 1; --i) {
                grid[i][c] = 0;
                uf.unite(i * w + c, (i + 1) * w + c);
            }
            // Down
            for (int i = r + 1; i < h && grid[i][c] == 1; ++i) {
                grid[i][c] = 0;
                uf.unite(i * w + c, (i - 1) * w + c);
            }
            // Left
            for (int j = c - 1; j >= 0 && grid[r][j] == 1; --j) {
                grid[r][j] = 0;
                uf.unite(r * w + j, r * w + j + 1);
            }
            // Right
            for (int j = c + 1; j < w && grid[r][j] == 1; ++j) {
                grid[r][j] = 0;
                uf.unite(r * w + j, r * w + j - 1);
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;

    return 0;
}