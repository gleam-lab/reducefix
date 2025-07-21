#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int TOP_K = 10;

int parent[MAXN];
set<int> component_info[MAXN]; // Store top 10 largest nodes in each component

// Find function with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two components. Always merge smaller into larger.
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Always merge smaller set into larger set to optimize DSU performance
    if (component_info[root_u].size() < component_info[root_v].size()) {
        swap(root_u, root_v);
    }

    // Move elements from root_v to root_u
    for (int node : component_info[root_v]) {
        component_info[root_u].insert(node);
        if (component_info[root_u].size() > TOP_K) {
            // Remove the smallest if we exceed TOP_K
            component_info[root_u].erase(prev(component_info[root_u].end()));
        }
    }

    // Attach root_v's parent to root_u
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and component info
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component_info[i].insert(i);
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } 
        else if (type == 2) {
            int v, k;
            cin >> v >> k;

            int root = find(v);
            auto& comp_set = component_info[root];

            if ((int)comp_set.size() < k) {
                cout << -1 << "\n";
            } else {
                // Get the k-th largest element
                auto it = comp_set.rbegin(); // reverse iterator (descending order)
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}