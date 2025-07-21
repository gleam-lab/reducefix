#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int parent[MAXN];
vector<int> top_nodes[MAXN];

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

    // Always attach smaller tree to larger tree
    if (top_nodes[root_u].size() < top_nodes[root_v].size())
        swap(root_u, root_v);

    // Merge the nodes
    for (int node : top_nodes[root_v]) {
        top_nodes[root_u].push_back(node);
    }

    // Sort in descending order and keep top K
    sort(top_nodes[root_u].begin(), top_nodes[root_u].end(), greater<int>());
    if (top_nodes[root_u].size() > K)
        top_nodes[root_u].resize(K);

    // Update parent
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and top nodes
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_nodes[i] = {i};
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
            if (k <= top_nodes[root].size()) {
                cout << top_nodes[root][k - 1] << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }

    return 0;
}