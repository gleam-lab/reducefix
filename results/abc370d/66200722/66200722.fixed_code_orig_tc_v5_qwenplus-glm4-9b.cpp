#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_H = 4e5 + 10;
const int MAX_W = 4e5 + 10;
const int MAX_Q = 2e5 + 10;

vector<int> parent(MAX_H * MAX_W);

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize Union-Find
    for (int i = 0; i < H * W; i++) {
        parent[i] = i;
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;

        int index = (R - 1) * W + (C - 1);

        // Check and destroy walls
        if (find(index) == index) {
            // Destroy the wall at (R, C)
            parent[index] = -1;  // Mark this wall as destroyed
        } else {
            // Destroy all connected walls
            int root = find(index);
            while (index != root) {
                parent[index] = -1;  // Mark this wall as destroyed
                index = find(index);
            }
        }
    }

    int remainingWalls = 0;
    for (int i = 0; i < H * W; i++) {
        if (parent[i] != -1) {
            remainingWalls++;
        }
    }

    cout << remainingWalls << endl;

    return 0;
}