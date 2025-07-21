#include <iostream>
#include <vector>
#include <algorithm>

struct UnionFind {
    std::vector<int> parent;
    std::vector<int> size;
    std::vector<std::vector<int>> trees; // each element is a balanced BST

    UnionFind(int n) : parent(n + 1), size(n + 1, 1) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                std::swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            // Merge trees
            trees[rootX].insert(trees[rootY].begin(), trees[rootY].end());
        }
    }
};

int main() {
    int n, q;
    std::cin >> n >> q;

    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int type, x, y, k;
        std::cin >> type >> x >> y;
        if (type == 1) {
            uf.unionSets(x, y);
        } else if (type == 2) {
            std::cout << uf.trees[uf.find(x)][k - 1] << std::endl;
        }
    }

    return 0;
}