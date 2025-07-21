#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
vector<int> top_vertex[MAXN]; // Stores up to top 10 largest nodes

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets: small into large
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Always merge smaller into larger for efficiency
    if (top_vertex[fx].size() < top_vertex[fy].size())
        swap(fx, fy);

    // Merge the lists
    vector<int> merged;
    merged.reserve(top_vertex[fx].size() + top_vertex[fy].size());
    merged.insert(merged.end(), top_vertex[fx].begin(), top_vertex[fx].end());
    merged.insert(merged.end(), top_vertex[fy].begin(), top_vertex[fy].end());

    // Sort and keep top 10
    sort(merged.begin(), merged.end(), greater<int>());
    if (merged.size() > 10)
        merged.resize(10);

    // Update parent
    parent[fy] = fx;
    top_vertex[fx] = merged;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_vertex[i] = {i};
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
            if (top_vertex[root].size() < k)
                cout << -1 << '\n';
            else
                cout << top_vertex[root][k - 1] << '\n';
        }
    }

    return 0;
}