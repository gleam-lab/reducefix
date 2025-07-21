#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100000 + 5;

int parent[MAXN];
vector<int> top_vertices[MAXN];

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
    if (top_vertices[fx].size() < top_vertices[fy].size())
        swap(fx, fy);

    // Merge top vertices
    for (int v : top_vertices[fy])
        top_vertices[fx].push_back(v);

    // Sort and keep top 10
    sort(top_vertices[fx].begin(), top_vertices[fx].end(), greater<int>());
    if (top_vertices[fx].size() > 10)
        top_vertices[fx].resize(10);

    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_vertices[i].push_back(i);
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
            int rep = find(v);
            if (k <= top_vertices[rep].size())
                cout << top_vertices[rep][k - 1] << "\n";
            else
                cout << "-1\n";
        }
    }

    return 0;
}