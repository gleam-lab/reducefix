#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> *connected_components[MAXN]; // Store top K elements in descending order

// Find the root of the set (with path compression)
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union two sets (smaller component gets merged into larger one)
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Merge smaller set into larger set to keep tree shallow
    if (connected_components[root_u]->size() < connected_components[root_v]->size()) {
        swap(root_u, root_v);
    }

    // Merge the components
    for (int node : *connected_components[root_v]) {
        connected_components[root_u]->insert(node);
    }

    parent[root_v] = root_u;
    delete connected_components[root_v]; // Free memory
    connected_components[root_v] = nullptr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        connected_components[i] = new set<int, greater<int>>();
        connected_components[i]->insert(i);
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            
            int root_v = find(v);
            
            if (connected_components[root_v]->size() < (size_t)k) {
                cout << -1 << "\n";
            } else {
                auto it = connected_components[root_v]->begin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    // Clean up dynamically allocated sets
    for (int i = 1; i <= N; ++i) {
        if (connected_components[i])
            delete connected_components[i];
    }

    return 0;
}