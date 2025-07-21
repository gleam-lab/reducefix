#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
vector<int> top_nodes[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    // Always attach smaller tree to larger one
    if (top_nodes[px].size() < top_nodes[py].size())
        swap(px, py);

    // Merge the top nodes
    for (int val : top_nodes[py])
        top_nodes[px].push_back(val);

    // Sort and keep top 10 largest values
    sort(top_nodes[px].rbegin(), top_nodes[px].rend());
    if (top_nodes[px].size() > 10)
        top_nodes[px].resize(10);

    parent[py] = px;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
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
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (k > top_nodes[root].size())
                cout << "-1\n";
            else
                cout << top_nodes[root][k - 1] << "\n";
        }
    }

    return 0;
}