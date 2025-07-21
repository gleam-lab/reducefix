#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 2 * 100000 + 10;

int parent[MAXN];
ordered_set components[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
        return;

    // Merge smaller set into larger set
    if (components[pu].size() < components[pv].size())
        swap(pu, pv);

    for (int x : components[pv]) {
        components[pu].insert(x);
    }

    parent[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and ordered sets
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i); // Store actual values
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
            if (components[root].size() < k) {
                cout << -1 << "\n";
            } else {
                // k-th largest = size - k-th smallest in descending order
                cout << *components[root].find_by_order(components[root].size() - k) << "\n";
            }
        }
    }

    return 0;
}