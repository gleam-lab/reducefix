#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
vector<int> top_vals[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;

    // Merge smaller set into larger one
    if (top_vals[fx].size() < top_vals[fy].size())
        swap(fx, fy);

    // Append and sort the top values
    top_vals[fx].insert(top_vals[fx].end(), top_vals[fy].begin(), top_vals[fy].end());
    sort(top_vals[fx].begin(), top_vals[fx].end(), greater<int>());
    if (top_vals[fx].size() > 10)
        top_vals[fx].resize(10);

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
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (top_vals[root].size() >= k)
                cout << top_vals[root][k - 1] << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}