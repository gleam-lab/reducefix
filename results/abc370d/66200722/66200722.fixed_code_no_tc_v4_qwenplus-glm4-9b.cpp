#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    UnionFind uf(W);  // Union-Find for W rows

    vector<vector<int>> destroyed(H, vector<int>(W, 0));  // Track destroyed walls

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r;  // Convert to 0-indexed
        --c;
        if (!destroyed[r][c]) {
            destroyed[r][c] = 1;  // Mark the wall as destroyed

            // Check and destroy vertical walls
            int vertical = c;
            while (vertical >= 0 && !destroyed[r][vertical]) {
                uf.unite(r, vertical);
                vertical--;
            }
            vertical = c + 1;
            while (vertical < W && !destroyed[r][vertical]) {
                uf.unite(r, vertical);
                vertical++;
            }

            // Check and destroy horizontal walls
            int horizontal = r;
            while (horizontal >= 0 && !destroyed[horizontal][c]) {
                uf.unite(horizontal, c);
                horizontal--;
            }
            horizontal = r + 1;
            while (horizontal < H && !destroyed[horizontal][c]) {
                uf.unite(horizontal, c);
                horizontal++;
            }
        }
    }

    // Calculate the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!destroyed[i][j]) {
                int root = uf.find(j);
                if (uf.rank[root] == 0) {
                    remainingWalls++;
                }
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}