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
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Always merge smaller into larger
    if (top_nodes[fx].size() < top_nodes[fy].size())
        swap(fx, fy);

    // Merge top nodes
    for (int node : top_nodes[fy]) {
        top_nodes[fx].push_back(node);
    }

    // Sort and keep top 10 largest
    sort(top_nodes[fx].begin(), top_nodes[fx].end(), greater<int>());
    if (top_nodes[fx].size() > 10)
        top_nodes[fx].resize(10);

    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_nodes[i] = {i};
    }

    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (k <= (int)top_nodes[root].size())
                cout << top_nodes[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}