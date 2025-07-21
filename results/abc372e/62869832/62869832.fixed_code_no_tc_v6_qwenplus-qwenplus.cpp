#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> *connected_components[MAXN]; // Store top k+ largest vertices in descending order

// Find the root of the set containing x with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets: small to large technique
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v)
        return;

    // Always merge smaller set into larger one
    if (connected_components[root_u]->size() < connected_components[root_v]->size()) {
        swap(root_u, root_v);
    }

    // Merge the contents of root_v into root_u
    for (int val : *connected_components[root_v]) {
        connected_components[root_u]->insert(val);
    }

    // Update parent
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        connected_components[i] = new set<int, greater<int>>();
        connected_components[i]->insert(i); // Each node initially contains itself
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root_v = find(v);
            if (k <= connected_components[root_v]->size()) {
                auto it = connected_components[root_v]->begin();
                advance(it, k - 1);
                cout << *it << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    // Clean up dynamically allocated sets
    for (int i = 1; i <= N; ++i) {
        delete connected_components[i];
    }

    return 0;
}