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
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y)
        return;

    // Always merge smaller into larger
    if (top_nodes[root_x].size() < top_nodes[root_y].size())
        swap(root_x, root_y);

    // Merge top nodes
    for (int node : top_nodes[root_y])
        top_nodes[root_x].push_back(node);

    // Sort and keep top 10
    sort(top_nodes[root_x].rbegin(), top_nodes[root_x].rend());
    if (top_nodes[root_x].size() > 10)
        top_nodes[root_x].resize(10);

    parent[root_y] = root_x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
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