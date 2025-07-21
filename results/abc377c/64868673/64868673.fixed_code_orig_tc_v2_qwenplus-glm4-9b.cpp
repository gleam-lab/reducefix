#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) : parent(n), size(n, 1) {
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
    int n, m;
    cin >> n >> m;

    DSU dsu(n * n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int index = (a - 1) * n + (b - 1);

        // Check the 8 possible capture directions
        vector<pair<int, int>> moves = {
            {1, 2}, {2, 1}, {2, -1}, {1, -2},
            {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
        };

        for (auto move : moves) {
            int x = a + move.first;
            int y = b + move.second;
            if (x > 0 && x <= n && y > 0 && y <= n) {
                int targetIndex = (x - 1) * n + (y - 1);
                dsu.unionSets(index, targetIndex);
            }
        }
    }

    // Count the number of unique sets
    vector<int> groupSizes;
    for (int i = 0; i < n * n; ++i) {
        int root = dsu.find(i);
        if (find(groupSizes.end(), groupSizes.begin(), root) == groupSizes.end()) {
            groupSizes.push_back(root);
        }
    }

    // Total cells minus the number of cells in sets
    int totalCells = n * n;
    int unsafeCells = groupSizes.size();
    cout << totalCells - unsafeCells << endl;

    return 0;
}