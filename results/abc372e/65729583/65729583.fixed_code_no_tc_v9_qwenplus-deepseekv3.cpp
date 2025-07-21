#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 9;
int parent[N];
vector<int> adj[N]; // Stores up to 10 largest connected vertices for each component

int Find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    
    if (adj[u].size() < adj[v].size()) swap(u, v);
    
    // Merge v's list into u's list
    adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
    adj[v].clear();
    
    // Sort and keep only top 10 elements
    sort(adj[u].begin(), adj[u].end(), greater<int>());
    if (adj[u].size() > 10) adj[u].resize(10);
    
    parent[v] = u;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        adj[i].push_back(i); // Each node is initially connected to itself
    }
    
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int u, v;
            cin >> u >> v;
            Union(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = Find(v);
            if (adj[v].size() < k) {
                cout << -1 << "\n";
            } else {
                cout << adj[v][k-1] << "\n";
            }
        }
    }
    
    return 0;
}