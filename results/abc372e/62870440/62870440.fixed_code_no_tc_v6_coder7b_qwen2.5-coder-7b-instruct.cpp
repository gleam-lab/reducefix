#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOGN = 20;

vector<int> adj[MAXN];
int depth[MAXN], parent[MAXN][LOGN];

void dfs(int node, int par) {
    parent[node][0] = par;
    depth[node] = depth[par] + 1;
    for (int i = 1; i < LOGN; ++i) {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
}

int getKthParent(int node, int k) {
    for (int i = 0; i < LOGN; ++i) {
        if (k & (1 << i)) {
            node = parent[node][i];
            if (node == -1) break;
        }
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i][0] = -1;
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            int v, k;
            cin >> v >> k;
            int parentV = getKthParent(v, k);
            if (parentV == -1) cout << "-1\n";
            else cout << parentV << "\n";
        }
    }
    
    return 0;
}