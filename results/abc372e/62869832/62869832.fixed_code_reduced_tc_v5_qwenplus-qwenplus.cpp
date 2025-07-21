#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN];
set<int> components[MAXN]; // Each root maintains a sorted set of nodes in its component

// Find the root of the set with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union by size
bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return false;

    // Always merge smaller set into larger set
    if (components[rootX].size() < components[rootY].size()) {
        swap(rootX, rootY);
    }

    // Merge components: insert all elements from rootY to rootX
    components[rootX].insert(components[rootY].begin(), components[rootY].end());
    components[rootY].clear(); // Clear the old set

    parent[rootY] = rootX;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i); // Initially each node is alone in its component
    }

    while (Q--) {
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
                // Access the k-th largest element using reverse iterator
                auto it = components[root].rbegin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}