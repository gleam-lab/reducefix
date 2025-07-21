#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
using ll = long long;

// Find the root of vertex x with path compression
int findRoot(int x, vector<int>& parent) {
    if (parent[x] != x) parent[x] = findRoot(parent[x], parent);
    return parent[x];
}

// Unite two sets by rank
bool unite(int x, int y, vector<int>& parent, vector<int>& rank) {
    int rx = findRoot(x, parent), ry = findRoot(y, parent);
    if (rx == ry) return false;
    if (rank[rx] < rank[ry]) {
        swap(rx, ry);
    }
    parent[ry] = rx;
    if (rank[rx] == rank[ry]) rank[rx]++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> parent(n);
    vector<int> rank(n, 0);
    rep(i, n) parent[i] = i;

    vector<vector<int>> adj(n); // Adjacency list of the graph

    while (q--) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            unite(u, v, parent, rank);
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            int rootV = findRoot(v, parent);
            if (k > adj[rootV].size()) cout << -1 << endl;
            else cout << adj[rootV][adj[rootV].size() - k] + 1 << endl;
        }
    }

    return 0;
}