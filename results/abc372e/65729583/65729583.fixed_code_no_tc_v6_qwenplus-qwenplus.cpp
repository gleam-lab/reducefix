#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 2 * 100000 + 5;

int parent[MAXN];
ordered_set components[MAXN];

// Find with path compression
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

// Union by size
void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU == rootV)
        return;

    // Always merge smaller set into larger one
    if (components[rootU].size() < components[rootV].size()) {
        swap(rootU, rootV);
    }

    // Merge the smaller component into the larger one
    for (auto it = components[rootV].begin(); it != components[rootV].end(); ++it) {
        components[rootU].insert(*it);
    }
    
    parent[rootV] = rootU;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize each node as its own component
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);  // Store actual vertex numbers
    }

    for (int i = 0; i < Q; ++i) {
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
            
            if (components[root].size() < k) {
                cout << -1 << endl;
            } else {
                // Use order_of_key to get the k-th largest
                auto it = components[root].end();
                advance(it, -k);
                cout << *it << endl;
            }
        }
    }

    return 0;
}