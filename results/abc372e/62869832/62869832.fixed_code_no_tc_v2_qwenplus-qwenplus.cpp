#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> components[MAXN]; // Store top K nodes in descending order

// Find the root of the set (path compression)
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Merge two sets: merge small set into large one for efficiency
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v) return;

    // Always merge smaller component into larger one
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
    }

    // Move elements from root_v to root_u
    for (auto node : components[root_v]) {
        if (components[root_u].size() < K_MAX) {
            components[root_u].insert(node);
        } else {
            break; // No need to add more than K_MAX elements
        }
    }

    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and components
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
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
            
            if (components[root].size() >= k) {
                auto it = components[root].begin();
                advance(it, k - 1);
                cout << *it << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}