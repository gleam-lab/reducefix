#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];

void dfs(int node, int parent, vector<int>& depth, vector<vector<int>>& ancestors) {
    depth[node] = depth[parent] + 1;
    ancestors[node][0] = parent;
    for(int i = 1; i <= 10; ++i) {
        if(ancestors[node][i-1] == -1) break;
        ancestors[node][i] = ancestors[ancestors[node][i-1]][i-1];
    }
    for(auto child : adj[node]) {
        if(child != parent) dfs(child, node, depth, ancestors);
    }
}

int lca(int u, int v, vector<int>& depth, vector<vector<int>>& ancestors) {
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for(int i = 0; i <= 10; ++i) {
        if(diff & (1 << i)) v = ancestors[v][i];
    }
    if(u == v) return u;
    for(int i = 10; i >= 0; --i) {
        if(ancestors[u][i] != ancestors[v][i]) {
            u = ancestors[u][i];
            v = ancestors[v][i];
        }
    }
    return ancestors[u][0];
}

int kthAncestor(int u, int k, vector<int>& depth, vector<vector<int>>& ancestors) {
    if(k >= depth[u]) return -1;
    for(int i = 0; i <= 10; ++i) {
        if(k & (1 << i)) u = ancestors[u][i];
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(n+1, -1);
    vector<vector<int>> ancestors(n+1, vector<int>(11, -1));
    dfs(1, 1, depth, ancestors);
    while(q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if(type == 1) {
            // No need to handle type 1 query here as it's handled during DFS
        } else {
            int lcaNode = lca(v, v, depth, ancestors);
            int result = kthAncestor(v, depth[v] - depth[lcaNode] + k, depth, ancestors);
            cout << result << '\n';
        }
    }
    return 0;
}