#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int parent[MAXN];
multiset<int, greater<int>> components[MAXN];

// Find function with path compression
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

// Union function to merge smaller component into larger one
void unite(int u, int v, int N) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU == rootV)
        return;

    // Ensure rootU is the larger set
    if (components[rootU].size() < components[rootV].size()) {
        swap(rootU, rootV);
    }

    // Merge smaller set into larger one
    components[rootU].insert(components[rootV].begin(), components[rootV].end());
    parent[rootV] = rootU;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    for (int q = 0; q < Q; ++q) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v, N);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (components[root].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = components[root].begin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}