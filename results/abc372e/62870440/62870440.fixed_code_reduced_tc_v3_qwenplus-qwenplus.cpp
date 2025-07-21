#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int TOP_SIZE = 10;

int parent[MAXN];
vector<int> top_vals[MAXN];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union with merging smaller set into larger one
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Always merge fy into fx
    if (top_vals[fx].size() < top_vals[fy].size()) swap(fx, fy);

    for (int val : top_vals[fy]) {
        top_vals[fx].push_back(val);
    }

    // Sort descending and keep only top 10
    sort(top_vals[fx].begin(), top_vals[fx].end(), greater<int>());
    if (top_vals[fx].size() > TOP_SIZE)
        top_vals[fx].resize(TOP_SIZE);

    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and top_vals
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
            int root = find(v);
            if ((int)top_vals[root].size() < k)
                cout << -1 << '\n';
            else
                cout << top_vals[root][k - 1] << '\n';
        }
    }

    return 0;
}