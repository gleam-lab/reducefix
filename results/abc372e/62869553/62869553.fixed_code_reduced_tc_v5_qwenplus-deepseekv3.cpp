#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int parent[MAXN];
vector<int> adj[MAXN];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (adj[u].size() < adj[v].size())
            swap(u, v);
        parent[v] = u;
        adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
        adj[v].clear();
        sort(adj[u].rbegin(), adj[u].rend());
        if (adj[u].size() > 10)
            adj[u].resize(10);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        adj[i] = {i};
    }
    
    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else {
            u = find(u);
            if (adj[u].size() < v) {
                cout << -1 << '\n';
            } else {
                cout << adj[u][v-1] << '\n';
            }
        }
    }
    
    return 0;
}