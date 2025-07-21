#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 200005;

int parent[MAXN];
ordered_set components[MAXN];

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

    // Always merge smaller set into larger one for better performance
    if (components[root_u].size() < components[root_v].size())
        swap(root_u, root_v);

    // Move all elements from smaller set to larger set
    for (int x : components[root_v]) {
        components[root_u].insert(x);
    }

    // Update parent
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and ordered sets
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if ((int)components[root].size() < k) {
                cout << -1 << '\n';
            } else {
                // Since we're using less<int>, elements are sorted ascending
                // Use size() - k to get k-th largest
                cout << *components[root].find_by_order((int)components[root].size() - k) << '\n';
            }
        }
    }

    return 0;
}