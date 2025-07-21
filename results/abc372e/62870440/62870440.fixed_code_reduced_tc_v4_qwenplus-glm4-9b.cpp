#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 200005;
const int MAX_K = 10;

vector<int> parent(MAX_V);
vector<int> size(MAX_V, 1);
vector<vector<int>> adj(MAX_V);
vector<vector<int>> sorted_adj(MAX_V);

int find_set(int u) {
    if (parent[u] != u) {
        parent[u] = find_set(parent[u]);
    }
    return parent[u];
}

void union_set(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) {
            swap(root_u, root_v);
        }
        parent[root_v] = root_u;
        size[root_u] += size[root_v];
    }
}

void add_edge(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        union_set(u, v);
    }
}

void add_sorted_edge(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        union_set(u, v);
        sorted_adj[root_u].push_back(v);
        sorted_adj[root_v].push_back(u);
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        // Initialize sorted_adj here
    }

    for (int i = 0; i < q; ++i) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if (type == 1) {
            add_edge(u, v);
            add_sorted_edge(u, v);
        } else if (type == 2) {
            int root_v = find_set(v);
            if (sorted_adj[root_v].size() < k) {
                cout << -1 << "\n";
            } else {
                cout << sorted_adj[root_v][sorted_adj[root_v].size() - k] << "\n";
            }
        }
    }

    return 0;
}