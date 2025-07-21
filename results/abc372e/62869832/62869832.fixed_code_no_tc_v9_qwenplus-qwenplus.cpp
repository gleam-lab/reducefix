#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int> component[MAXN]; // Store vertices in each connected component

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
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
        component[i].insert(i);
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            int root_u = find(u);
            int root_v = find(v);

            if (root_u != root_v) {
                // Merge smaller set into larger one to optimize performance
                if (component[root_u].size() < component[root_v].size()) {
                    swap(root_u, root_v);
                }

                // Merge the sets
                for (int node : component[root_v]) {
                    component[root_u].insert(node);
                    parent[node] = root_u;
                }
                component[root_v].clear();
            }
        } else {
            int v, k;
            cin >> v >> k;
            int root_v = find(v);
            
            if (k > (int)component[root_v].size()) {
                cout << -1 << '\n';
            } else {
                // Get the k-th largest using reverse iterator
                auto it = component[root_v].rbegin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}