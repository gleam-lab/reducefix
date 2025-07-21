#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOGN = 18; // log2(MAXN)

vector<int> adj[MAXN]; // Adjacency list for the graph
int depth[MAXN], parent[MAXN][LOGN];

void dfs(int node, int par) {
    parent[node][0] = par;
    depth[node] = (par != -1 ? depth[par] + 1 : 0);
    
    for(int child : adj[node]) {
        if(child == par) continue;
        dfs(child, node);
    }
}

void preprocessLCA() {
    for(int j = 1; j < LOGN; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    
    int diff = depth[v] - depth[u];
    for(int i = 0; i < LOGN; ++i) {
        if((diff >> i) & 1) {
            v = parent[v][i];
        }
    }
    
    if(u == v) return u;
    
    for(int i = LOGN - 1; i >= 0; --i) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    
    return parent[u][0];
}

int main() {
    cin >> n >> q;
    
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, -1); // Assuming node 1 is the root
    preprocessLCA();
    
    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            cout << LCA(u, v) << endl;
        } else {
            int v, k;
            cin >> v >> k;
            // Handle Type 2 query here if needed
        }
    }
    
    return 0;
}