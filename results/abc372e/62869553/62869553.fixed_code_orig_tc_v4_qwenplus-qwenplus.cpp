#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 5;
const int TOP_K = 10;

int parent[MAXN];
vector<int> top_nodes[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;

    // Merge smaller component into larger one
    if (top_nodes[px].size() < top_nodes[py].size()) swap(px, py);

    // Merge the top-k lists
    for (int val : top_nodes[py]) {
        top_nodes[px].push_back(val);
    }

    // Sort and keep top 10 largest values
    sort(top_nodes[px].begin(), top_nodes[px].end(), greater<int>());
    if (top_nodes[px].size() > TOP_K) {
        top_nodes[px].resize(TOP_K);
    }

    // Update DSU parent
    parent[py] = px;
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
            int pv = find(v);
            if (top_nodes[pv].size() < k) {
                cout << -1 << '\n';
            } else {
                cout << top_nodes[pv][k - 1] << '\n';
            }
        }
    }

    return 0;
}