#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 5;

int parent[MAX_N + 1];
int size[MAX_N + 1];
vector<int> adj_list[MAX_N + 1];

int find_set(int x) {
    if (parent[x] != x) {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find_set(x);
    int rootY = find_set(y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        // Merge the adjacency lists
        for (int node : adj_list[rootY]) {
            adj_list[rootX].push_back(node);
        }
        adj_list[rootY].clear();
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    // Initialize parent and size arrays
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
    }

    // Process queries
    for (int q = 0; q < Q; ++q) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            union_sets(u, v);
        } else if (type == 2) {
            int rootV = find_set(v);
            int k;
            cin >> k;
            // Keep a sorted list of all vertices in the connected component
            sort(adj_list[rootV].rbegin(), adj_list[rootV].rend());
            if (k > 1 && k <= adj_list[rootV].size()) {
                cout << adj_list[rootV][k - 1] << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}