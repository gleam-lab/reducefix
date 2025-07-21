#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int KMAX = 10;

int n, q;
int parent[MAXN];
set<int, greater<int>> *connected_components[MAXN]; // Stores top K elements in descending order

// Find the root of the set (with path compression)
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Merge two sets: merge y into x
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return;

    // Always merge smaller set into larger one for efficiency
    if (connected_components[rootX]->size() < connected_components[rootY]->size()) {
        swap(rootX, rootY);
    }

    // Merge the elements from rootY to rootX maintaining k largest elements
    for (int val : *connected_components[rootY]) {
        if (connected_components[rootX]->size() < KMAX) {
            connected_components[rootX]->insert(val);
        } else if (val > *connected_components[rootX]->rbegin()) {
            connected_components[rootX]->erase(*connected_components[rootX]->rbegin());
            connected_components[rootX]->insert(val);
        }
    }

    parent[rootY] = rootX;
    delete connected_components[rootY]; // Free memory
    connected_components[rootY] = nullptr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    // Initialize DSU
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        connected_components[i] = new set<int, greater<int>>();
        connected_components[i]->insert(i);
    }

    while (q--) {
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
            auto& component = *connected_components[root];

            if (component.size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = component.begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    // Cleanup dynamically allocated sets
    for (int i = 1; i <= n; ++i) {
        if (connected_components[i]) {
            delete connected_components[i];
        }
    }

    return 0;
}