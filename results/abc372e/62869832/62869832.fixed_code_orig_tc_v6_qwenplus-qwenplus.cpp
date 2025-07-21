#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int N, Q;
vector<int> topNodes[MAXN]; // Stores top 10 largest vertices for each component

// Union-Find with path compression
int parent[MAXN];
int size[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;

    // Always merge smaller into larger
    if (size[pu] < size[pv]) swap(pu, pv);
    
    // Merge top nodes
    for (int val : topNodes[pv]) {
        topNodes[pu].push_back(val);
    }
    sort(topNodes[pu].rbegin(), topNodes[pu].rend());
    if (topNodes[pu].size() > 10)
        topNodes[pu].resize(10);

    // Union by size
    parent[pv] = pu;
    size[pu] += size[pv];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    // Initialize DSU and topNodes
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
        topNodes[i].push_back(i);
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
            if ((int)topNodes[root].size() < k)
                cout << -1 << '\n';
            else
                cout << topNodes[root][k - 1] << '\n';
        }
    }

    return 0;
}