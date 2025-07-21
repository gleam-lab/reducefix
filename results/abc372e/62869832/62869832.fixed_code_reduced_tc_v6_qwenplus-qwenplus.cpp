#include <bits/stdc++.h>
using namespace std;

const int K = 10;
const int MAXN = 2 * 1e5 + 5;

int parent[MAXN];
vector<int> top_vals[MAXN];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;

    // Always attach smaller tree to bigger one
    parent[pv] = pu;

    // Merge the top K values
    vector<int> merged;
    merged.insert(merged.end(), top_vals[pu].begin(), top_vals[pu].end());
    merged.insert(merged.end(), top_vals[pv].begin(), top_vals[pv].end());

    // Sort descending and take top K
    sort(merged.begin(), merged.end(), greater<int>());
    if (merged.size() > K)
        merged.resize(K);

    top_vals[pu] = merged;
}

int query(int v, int k) {
    int root = find(v);
    if (top_vals[root].size() < k)
        return -1;
    return top_vals[root][k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_vals[i].push_back(i);
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
            cout << query(v, k) << '\n';
        }
    }

    return 0;
}