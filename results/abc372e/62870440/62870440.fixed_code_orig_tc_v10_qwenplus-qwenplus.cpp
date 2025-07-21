#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int TOP_K = 20;

int parent[MAXN];
vector<int> top_nodes[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v)
        return;

    // Always merge smaller into larger
    if (top_nodes[root_u].size() < top_nodes[root_v].size())
        swap(root_u, root_v);

    // Merge top nodes
    for (int node : top_nodes[root_v]) {
        top_nodes[root_u].push_back(node);
    }

    // Sort and keep top TOP_K values
    sort(top_nodes[root_u].begin(), top_nodes[root_u].end(), greater<int>());
    if (top_nodes[root_u].size() > TOP_K)
        top_nodes[root_u].resize(TOP_K);

    // Update parent
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_nodes[i].push_back(i);
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root_v = find(v);
            if (top_nodes[root_v].size() < k)
                cout << -1 << '\n';
            else
                cout << top_nodes[root_v][k - 1] << '\n';
        }
    }

    return 0;
}