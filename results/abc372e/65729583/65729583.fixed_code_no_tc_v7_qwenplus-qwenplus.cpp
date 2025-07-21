#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 2 * 100000 + 5;

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

    // Always merge smaller component into larger one for efficiency
    if (components[root_u].size() < components[root_v].size())
        swap(root_u, root_v);

    // Merge the smaller set into the larger one
    for (auto it = components[root_v].begin(); it != components[root_v].end(); ++it) {
        components[root_u].insert(*it);
    }

    // Update parent pointer
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and components
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);  // Store actual vertex numbers
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
            int root = find(v);

            if (components[root].size() < k)
                cout << -1 << "\n";
            else {
                // Get k-th largest element
                auto it = components[root].end();
                --it;
                for (int i = 1; i < k; ++i)
                    --it;
                cout << *it << "\n";
            }
        }
    }

    return 0;
}