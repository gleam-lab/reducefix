#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 5;
const int K_LIMIT = 10;

int N, Q;
int parent[MAXN];
vector<int> top_nodes[MAXN];

// Find function with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets and keep top K_LIMIT elements
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Always attach smaller tree to larger one
    if (top_nodes[fx].size() < top_nodes[fy].size())
        swap(fx, fy);

    // Merge top_k lists
    vector<int> merged;
    merged.reserve(top_nodes[fx].size() + top_nodes[fy].size());
    merged.insert(merged.end(), top_nodes[fx].begin(), top_nodes[fx].end());
    merged.insert(merged.end(), top_nodes[fy].begin(), top_nodes[fy].end());

    // Sort descending and keep top K_LIMIT
    sort(merged.begin(), merged.end(), greater<int>());
    merged.resize(min(K_LIMIT, (int)merged.size()));

    top_nodes[fx] = merged;
    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    // Initialize DSU and top nodes
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
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if ((int)top_nodes[root].size() < k)
                cout << -1 << '\n';
            else
                cout << top_nodes[root][k - 1] << '\n';
        }
    }

    return 0;
}