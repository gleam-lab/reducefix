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
    int h, w, q;
    cin >> h >> w >> q;

    UnionFind uf(h * w);
    vector<vector<int>> grid(h, vector<int>(w, 0));

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c;

        if (grid[r][c] == 1) {
            grid[r][c] = 2; // Bomb placed, no walls left
        } else {
            // Find the first row without a wall to the left
            int left = c;
            while (left >= 0 && grid[r][left] == 2) {
                left--;
            }
            // Find the first row without a wall to the right
            int right = c;
            while (right < w && grid[r][right] == 2) {
                right++;
            }

            // Union the columns without any walls between them
            for (int j = left + 1; j < right; ++j) {
                uf.unite(j, j + w);
            }

            // Mark all walls in the row as destroyed
            for (int j = left; j <= right; ++j) {
                grid[r][j] = 2;
            }
        }
    }

    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 1) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;

    return 0;
}