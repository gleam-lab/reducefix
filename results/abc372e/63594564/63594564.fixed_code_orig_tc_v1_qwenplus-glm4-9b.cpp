#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2 * 10e5 + 5;

vector<int> parent(N + 1), size(N + 1);
vector<int> maxVal(N + 1); // Stores the maximum value in the component

int find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
}

void uni(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) {
            swap(root_u, root_v);
        }
        size[root_u] += size[root_v];
        parent[root_v] = root_u;
        maxVal[root_u] = max(maxVal[root_u], maxVal[root_v]);
    }
}

int kth_largest(int v, int k) {
    int root = find(v);
    if (size[root] < k) return -1;
    // This function should return the k-th largest element in the component rooted at v
    // Implementation details depend on how we maintain maxVal and size during union
    // This is a complex part and would require additional data structures to keep track of elements efficiently
    // Placeholder for now
    return 0;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
        maxVal[i] = i; // Each vertex starts as its own component
    }

    while (q--) {
        int t, u, v, k;
        cin >> t >> u >> v;
        if (t == 1) {
            uni(u, v);
        } else if (t == 2) {
            cin >> k;
            cout << kth_largest(v, k) << endl;
        }
    }

    return 0;
}