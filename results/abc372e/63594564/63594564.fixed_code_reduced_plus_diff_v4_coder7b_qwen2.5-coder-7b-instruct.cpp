#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2 * 100005;
int parent[MAXN], rank[MAXN];
vector<pair<int, int>> edges[MAXN];

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;
    if (rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if (rank[u] == rank[v]) rank[v]++;
    edges[v].insert(edges[v].end(), edges[u].begin(), edges[u].end());
    sort(edges[v].begin(), edges[v].end(), greater<pair<int, int>>());
    if (edges[v].size() > 10) edges[v].resize(10);
}

int kthLargest(int u, int k) {
    u = find(u);
    if (k > edges[u].size()) return -1;
    return edges[u][k - 1].first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 1;
    }

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        
        if (type == 1) {
            int w;
            cin >> w;
            edges[u].emplace_back(w, v);
            edges[v].emplace_back(w, u);
            unite(u, v);
        } else {
            kthLargest(u, k);
            cout << kthLargest(u, k) << '\n';
        }
    }

    return 0;
}