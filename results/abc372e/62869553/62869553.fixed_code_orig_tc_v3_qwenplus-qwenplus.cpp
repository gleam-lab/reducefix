#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int TOP_K = 10;

int n, q;
int parent[MAXN];
vector<int> top_vals[MAXN];

// DSU find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge the two sets: merge y into x
void unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;

    // Always merge smaller into larger to optimize performance
    if (top_vals[fx].size() < top_vals[fy].size())
        swap(fx, fy);

    // Merge top_vals
    for (int val : top_vals[fy])
        top_vals[fx].push_back(val);

    // Sort and keep top 10
    sort(top_vals[fx].rbegin(), top_vals[fx].rend());
    if (top_vals[fx].size() > TOP_K)
        top_vals[fx].resize(TOP_K);

    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    // Initialize DSU
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        top_vals[i].push_back(i);
    }

    while (q--) {
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
            if (k <= top_vals[root].size())
                cout << top_vals[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}