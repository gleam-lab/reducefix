#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;

vector<int> adj[MAXN];
int parent[MAXN], rank[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rank[px] > rank[py]) swap(px, py);
    parent[px] = py;
    if (rank[px] == rank[py]) rank[py]++;
    // Merge smaller set into larger set and sort
    adj[py].insert(adj[py].end(), adj[px].begin(), adj[px].end());
    adj[px].clear();
    sort(adj[py].begin(), adj[py].end());
}

int getKthLargest(int v, int k) {
    int root = find(v);
    if (k > adj[root].size()) return -1;
    return adj[root][k - 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            cout << getKthLargest(v, u) << '\n';
        }
    }

    return 0;
}