#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
const int MAXLOGN = 20;

vector<int> adj[MAXN];
int parent[MAXN][MAXLOGN];
int depth[MAXN];

void dfs(int node, int par, int d) {
    parent[node][0] = par;
    depth[node] = d;
    for (int i = 1; i <= MAXLOGN; ++i) {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    for (auto neighbor : adj[node]) {
        if (neighbor == par) continue;
        dfs(neighbor, node, d + 1);
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);

    int diff = depth[v] - depth[u];
    for (int i = 0; i <= MAXLOGN; ++i) {
        if ((diff >> i) & 1)
            v = parent[v][i];
    }

    if (u == v)
        return u;

    for (int i = MAXLOGN; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int kthLargest(int v, int k) {
    vector<int> neighbors;
    for (auto neighbor : adj[v]) {
        if (neighbor != parent[v][0]) // Avoid counting the direct parent
            neighbors.push_back(neighbor);
    }
    sort(neighbors.begin(), neighbors.end());
    int n = neighbors.size();
    if (k > n)
        return -1;
    else
        return neighbors[n - k]; // Adjust index for 0-based array
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    memset(parent, -1, sizeof(parent));
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            cout << kthLargest(v, k) << '\n';
        }
    }

    return 0;
}