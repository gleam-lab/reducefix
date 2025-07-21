#include <bits/stdc++.h>
using namespace std;

const int K = 10;
const int MAXN = 2e5 + 5;

int parent[MAXN];
vector<int> top_vals[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;

    // Always merge smaller into larger
    if (top_vals[pu].size() < top_vals[pv].size())
        swap(pu, pv);

    // Merge the top values
    vector<int> merged;
    merged.reserve(top_vals[pu].size() + top_vals[pv].size());
    merged.insert(merged.end(), top_vals[pu].begin(), top_vals[pu].end());
    merged.insert(merged.end(), top_vals[pv].begin(), top_vals[pv].end());

    // Sort and keep top K elements
    sort(merged.begin(), merged.end(), greater<int>());
    if (merged.size() > K)
        merged.resize(K);

    // Update the representative
    parent[pv] = pu;
    top_vals[pu] = merged;
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
            if (top_vals[root].size() < k)
                cout << -1 << '\n';
            else
                cout << top_vals[root][k - 1] << '\n';
        }
    }

    return 0;
}