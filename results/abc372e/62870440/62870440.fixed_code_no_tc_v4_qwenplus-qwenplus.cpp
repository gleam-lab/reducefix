#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> component[MAXN]; // Stores top K elements in descending order

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge smaller set into larger set to optimize performance
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Ensure we merge smaller into larger
    if (component[root_u].size() < component[root_v].size())
        swap(root_u, root_v);

    // Merge the components
    for (int node : component[root_v]) {
        component[root_u].insert(node);
    }

    // Maintain only top K elements
    while (component[root_u].size() > K_MAX) {
        auto last = prev(component[root_u].end());
        component[root_u].erase(last);
    }

    // Update DSU parent
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    // Initialize each node as its own component
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i].insert(i);
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
            int root = find(v);
            if (component[root].size() < (size_t)k) {
                cout << -1 << "\n";
            } else {
                auto it = component[root].begin();
                for (int i = 1; i < k; ++i) ++it;
                cout << *it << "\n";
            }
        }
    }

    return 0;
}