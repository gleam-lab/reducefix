#include <bits/stdc++.h>

using namespace std;

#define SZ(s) ((int)s.size())

const int N = 200005;

vector<int> parent;
vector<vector<int>> top_vertices;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    // Always merge smaller into larger
    if (top_vertices[a].size() < top_vertices[b].size())
        swap(a, b);

    // Merge top 10 vertices of b into a
    for (int v : top_vertices[b])
        top_vertices[a].push_back(v);

    // Sort descending, keep top 10
    sort(top_vertices[a].begin(), top_vertices[a].end(), greater<int>());
    if (top_vertices[a].size() > 10)
        top_vertices[a].resize(10);

    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    top_vertices.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        top_vertices[i].push_back(i);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (SZ(top_vertices[root]) < k)
                cout << -1 << '\n';
            else
                cout << top_vertices[root][k - 1] << '\n';
        }
    }

    return 0;
}