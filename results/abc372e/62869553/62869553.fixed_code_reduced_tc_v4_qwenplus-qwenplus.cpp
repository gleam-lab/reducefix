#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int parent[MAXN];
vector<int> top_vals[MAXN];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets and keep top 10 largest vertices
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    // Always merge smaller into larger
    if (top_vals[x].size() < top_vals[y].size())
        swap(x, y);

    // Merge the top lists
    for (int v : top_vals[y])
        top_vals[x].push_back(v);

    // Sort and keep top 10
    sort(top_vals[x].rbegin(), top_vals[x].rend());
    if (top_vals[x].size() > 10)
        top_vals[x].resize(10);

    parent[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_vals[i] = {i};
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (k <= (int)top_vals[root].size())
                cout << top_vals[root][k - 1] << '\n';
            else
                cout << "-1\n";
        }
    }

    return 0;
}