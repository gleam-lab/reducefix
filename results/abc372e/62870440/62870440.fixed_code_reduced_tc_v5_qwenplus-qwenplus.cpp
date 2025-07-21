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

    // Merge the top values
    for (int val : top_vals[fy]) {
        top_vals[fx].push_back(val);
    }

    // Keep only top 20 values
    sort(top_vals[fx].begin(), top_vals[fx].end(), greater<int>());
    if (top_vals[fx].size() > 20)
        top_vals[fx].resize(20);

    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

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
            if (k > (int)top_vals[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << top_vals[root][k - 1] << '\n';
            }
        }
    }

    return 0;
}