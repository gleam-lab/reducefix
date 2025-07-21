#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN], rank[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] > rank[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
}

multiset<int> neighbors[MAXN];

void addEdge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    neighbors[u].insert(v);
    neighbors[v].insert(u);
    unite(u, v);
}

int kthLargestNeighbor(int u, int k) {
    u = find(u);
    if (neighbors[u].size() < k) return -1;
    auto it = neighbors[u].rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    init(n);

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            addEdge(u, v);
        } else {
            cin >> u >> k;
            cout << kthLargestNeighbor(u, k) << '\n';
        }
    }

    return 0;
}