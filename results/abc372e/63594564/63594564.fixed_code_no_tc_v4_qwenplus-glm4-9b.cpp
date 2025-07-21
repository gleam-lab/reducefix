#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define N 200005

vector<int> par;
vector<set<int>> adj;

int find(int v) {
    if (par[v] == v) return v;
    par[v] = find(par[v]);
    return par[v];
}

void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        par[u] = v;
        adj[v].insert(adj[u].begin(), adj[u].end());
        adj[u].clear();
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    par.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            union_sets(u, v);
        } else {
            v = find(v);
            if (adj[v].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << adj[v].rbegin()[v - 1] << '\n';
            }
        }
    }

    return 0;
}