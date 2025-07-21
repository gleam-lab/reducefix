#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
int sz[MAXN];
vector<int> top_nodes[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (sz[x] < sz[y]) swap(x, y);

    // Merge smaller set into larger one
    for (int val : top_nodes[y])
        top_nodes[x].push_back(val);

    // Sort and keep top 10 largest nodes
    sort(top_nodes[x].begin(), top_nodes[x].end(), greater<int>());
    if (top_nodes[x].size() > 10)
        top_nodes[x].resize(10);

    parent[y] = x;
    sz[x] += sz[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        sz[i] = 1;
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
            if (top_nodes[root].size() < k)
                cout << "-1\n";
            else
                cout << top_nodes[root][k - 1] << "\n";
        }
    }

    return 0;
}