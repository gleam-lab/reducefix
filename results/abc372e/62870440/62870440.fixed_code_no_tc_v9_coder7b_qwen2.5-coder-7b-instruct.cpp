#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
const int MAXLOGN = 20;

vector<int> adj[MAXN];
int parent[MAXN][MAXLOGN];

void dfs(int node, int par, int level) {
    parent[node][0] = par;
    for (int i = 1; i < MAXLOGN; ++i) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        }
    }
    for (int child : adj[node]) {
        if (child == par) continue;
        dfs(child, node, level + 1);
    }
}

int getKthAncestor(int node, int k) {
    for (int i = 0; i < MAXLOGN; ++i) {
        if ((k & (1 << i)) > 0) {
            node = parent[node][i];
            if (node == -1) break;
        }
    }
    return node;
}

int findKthLargest(int node, int k) {
    vector<int> temp;
    for (int child : adj[node]) {
        temp.push_back(child);
    }
    sort(temp.begin(), temp.end());
    if (temp.size() < k) return -1;
    return temp[temp.size() - k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    while (q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if (type == 1) {
            // Edge addition handled implicitly through adjacency list construction
        } else if (type == 2) {
            cout << findKthLargest(v, k) << "\n";
        }
    }

    return 0;
}