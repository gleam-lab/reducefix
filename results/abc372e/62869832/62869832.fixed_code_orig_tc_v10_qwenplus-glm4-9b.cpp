#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Node {
    int parent;
    std::vector<int> children;
};

Node nodes[200005]; // There can be up to 200,005 nodes

// Find the root of the component containing x, and compress paths
int find(int x) {
    if (nodes[x].parent != x) nodes[x].parent = find(nodes[x].parent);
    return nodes[x].parent;
}

// Union the components containing x and y
void union_components(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        // Union logic here (merge x's component into y's component)
        // Update neighbors accordingly
    }
}

int main() {
    int n, q;
    std::cin >> n >> q;

    for (int query; q--; ) {
        std::cin >> query;

        if (query == 1) {
            int u, v;
            std::cin >> u >> v;
            union_components(u, v);
        } else {
            int v, k;
            std::cin >> v >> k;
            // Query logic here
        }
    }

    return 0;
}