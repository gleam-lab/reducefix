#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 5;

int parent[MAXN];
vector<int> component[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    
    // Always merge smaller into larger
    if (component[px].size() < component[py].size())
        swap(px, py);

    // Merge py's component into px's
    component[px].insert(component[px].end(), component[py].begin(), component[py].end());
    sort(component[px].rbegin(), component[px].rend());  // Sort descending
    if (component[px].size() > 10)
        component[px].resize(10);  // Keep only top 10
    parent[py] = px;
    component[py].clear();  // Clear to avoid future interference
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i] = {i};
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
            if (component[root].size() < k)
                cout << -1 << '\n';
            else
                cout << component[root][k - 1] << '\n';
        }
    }

    return 0;
}