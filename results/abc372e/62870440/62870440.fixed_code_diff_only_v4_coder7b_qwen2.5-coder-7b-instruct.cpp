#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOGMAXN = 20;

vector<int> adj[MAXN];
int parent[MAXN][LOGMAXN];
int depth[MAXN];

void dfs(int node, int par) {
    parent[node][0] = par;
    depth[node] = (par != -1 ? depth[par] + 1 : 0);

    for (int i = 1; i < LOGMAXN; ++i) {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (auto child : adj[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
}

int getKthAncestor(int node, int k) {
    for (int i = 0; i < LOGMAXN; ++i) {
        if ((k & (1 << i)) > 0) {
            node = parent[node][i];
        }
        if (node == -1) break;
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i][0] = -1;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1); // Assuming the tree is rooted at node 1

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            // Since we are assuming a tree, this operation is not needed
            // It would be used in a forest or graph where multiple components exist
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int kthAncestor = getKthAncestor(v, k);
            if (kthAncestor == -1 || depth[kthAncestor] < k) {
                cout << "-1" << endl;
            } else {
                cout << kthAncestor << endl;
            }
        }
    }

    return 0;
}