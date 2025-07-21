#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
const int N = 2e5 + 9;

// Ordered set policy for storing vertex numbers in descending order
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int parent[N];
ordered_set components[N];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Union by size (attach smaller to larger)
    if (components[root_u].size() < components[root_v].size())
        swap(root_u, root_v);

    // Merge the smaller component into the larger one
    for (auto it = components[root_v].begin(); it != components[root_v].end(); ++it) {
        components[root_u].insert(*it);
    }

    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Initialize DSU and components
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);  // Store vertex in its own component
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);

            if (components[root].size() < k)
                cout << -1 << "\n";
            else
                cout << *components[root].find_by_order(k - 1) << "\n";  // k-th largest
        }
    }

    return 0;
}