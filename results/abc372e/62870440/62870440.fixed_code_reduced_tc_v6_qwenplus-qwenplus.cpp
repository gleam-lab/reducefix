#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K = 10;

int parent[MAXN];
vector<int> top_components[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv)
        return;

    // Always attach smaller tree to bigger tree
    if ((int)top_components[pu].size() > (int)top_components[pv].size())
        swap(pu, pv);

    // Merge top_components
    for (int val : top_components[pu]) {
        top_components[pv].push_back(val);
    }

    // Sort and keep top K elements
    sort(top_components[pv].rbegin(), top_components[pv].rend());
    if (top_components[pv].size() > K)
        top_components[pv].resize(K);

    parent[pu] = pv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        top_components[i].push_back(i);
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
            if ((int)top_components[root].size() < k)
                cout << -1 << "\n";
            else
                cout << top_components[root][k - 1] << "\n";
        }
    }

    return 0;
}