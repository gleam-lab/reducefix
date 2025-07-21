#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
vector<int> top_vertices[MAXN];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v) return;

    // Always merge smaller into larger
    if (top_vertices[root_u].size() < top_vertices[root_v].size())
        swap(root_u, root_v);

    // Merge the top K_MAX elements from both
    vector<int> merged;
    merged.reserve(top_vertices[root_u].size() + top_vertices[root_v].size());
    merged.insert(merged.end(), top_vertices[root_u].begin(), top_vertices[root_u].end());
    merged.insert(merged.end(), top_vertices[root_v].begin(), top_vertices[root_v].end());

    // Sort and keep top K_MAX largest
    sort(merged.begin(), merged.end(), greater<int>());
    if (merged.size() > K_MAX)
        merged.resize(K_MAX);

    // Update root and data
    parent[root_v] = root_u;
    top_vertices[root_u] = merged;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_vertices[i] = {i};
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
            if (top_vertices[root].size() < k)
                cout << -1 << '\n';
            else
                cout << top_vertices[root][k - 1] << '\n';
        }
    }

    return 0;
}