#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K = 10;

int n, q;
int parent[MAXN];
vector<int> top_nodes[MAXN];

// Find function with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge function for two sets
void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;

    // Always merge smaller into larger
    if (top_nodes[pu].size() < top_nodes[pv].size())
        swap(pu, pv);

    // Merge top nodes
    for (int val : top_nodes[pv])
        top_nodes[pu].push_back(val);

    // Sort in descending order and keep top K
    sort(top_nodes[pu].begin(), top_nodes[pu].end(), greater<int>());
    if (top_nodes[pu].size() > K)
        top_nodes[pu].resize(K);

    // Update parent
    parent[pv] = pu;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    // Initialize Union-Find and top_nodes
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        top_nodes[i].push_back(i);
    }

    while (q--) {
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
            if (k <= top_nodes[root].size())
                cout << top_nodes[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}