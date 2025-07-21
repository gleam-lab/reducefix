#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
vector<int> top_nodes[MAXN];

// Find function with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets, keeping only top K_MAX largest nodes
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Always attach smaller tree to larger tree
    if (top_nodes[fx].size() < top_nodes[fy].size())
        swap(fx, fy);

    // Merge the lists
    for (int node : top_nodes[fy])
        top_nodes[fx].push_back(node);

    // Sort and keep only top K_MAX largest nodes
    sort(top_nodes[fx].begin(), top_nodes[fx].end(), greater<int>());
    if (top_nodes[fx].size() > K_MAX)
        top_nodes[fx].resize(K_MAX);

    parent[fy] = fx;
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
            if (k <= top_nodes[root].size())
                cout << top_nodes[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}