#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int parent[MAXN], sz[MAXN];
vector<int> top_nodes[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;

    // Ensure smaller tree is merged into larger one
    if (sz[pu] < sz[pv]) swap(pu, pv);
    
    // Merge top K nodes from pv into pu
    vector<int> merged;
    int i = 0, j = 0;
    while (i < top_nodes[pu].size() && j < top_nodes[pv].size()) {
        merged.push_back(top_nodes[pu][i++] > top_nodes[pv][j++] ? top_nodes[pu][i-1] : top_nodes[pv][j-1]);
    }
    while (i < top_nodes[pu].size()) merged.push_back(top_nodes[pu][i++]);
    while (j < top_nodes[pv].size()) merged.push_back(top_nodes[pv][j++]);

    // Keep only top 10
    if (merged.size() > K) merged.resize(K);
    top_nodes[pu] = merged;

    // Update DSU structure
    parent[pv] = pu;
    sz[pu] += sz[pv];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and top nodes
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        sz[i] = 1;
        top_nodes[i].push_back(i);
    }

    for (int q = 0; q < Q; ++q) {
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
            if (top_nodes[root].size() < k)
                cout << "-1\n";
            else
                cout << top_nodes[root][k - 1] << "\n";
        }
    }

    return 0;
}