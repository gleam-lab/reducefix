#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
vector<int> top_vertices[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;

    // Always merge smaller into larger
    if (top_vertices[pu].size() < top_vertices[pv].size())
        swap(pu, pv);

    // Merge top_vertices[pv] into top_vertices[pu]
    for (int x : top_vertices[pv])
        top_vertices[pu].push_back(x);

    // Sort and keep top 10 largest values
    sort(top_vertices[pu].rbegin(), top_vertices[pu].rend());
    if (top_vertices[pu].size() > 10)
        top_vertices[pu].resize(10);

    parent[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_vertices[i].push_back(i);
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
            if (k <= (int)top_vertices[root].size()) {
                cout << top_vertices[root][k - 1] << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}