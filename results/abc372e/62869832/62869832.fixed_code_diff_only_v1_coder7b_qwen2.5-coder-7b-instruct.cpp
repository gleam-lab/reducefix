#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dp[200005][21];

void dfs(int node, int parent) {
    dp[node][0] = parent;
    for (int i = 1; i <= 19; ++i) {
        if (dp[node][i - 1] != -1) {
            dp[node][i] = dp[dp[node][i - 1]][i - 1];
        } else {
            dp[node][i] = -1;
        }
    }
    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node);
    }
}

int getKthAncestor(int node, int k) {
    while (k > 0) {
        int x = log2(k);
        node = dp[node][x];
        k -= (1 << x);
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 21; ++j) {
            dp[i][j] = -1;
        }
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for (int i = 1; i <= q; ++i) {
        int type, v, k;
        cin >> type >> v >> k;
        if (type == 2) {
            if (adj[v].size() < k) {
                cout << "-1\n";
            } else {
                vector<int> temp;
                for (auto child : adj[v]) {
                    temp.push_back(getKthAncestor(child, adj[child].size()));
                }
                sort(temp.begin(), temp.end());
                cout << temp[k - 1] << "\n";
            }
        }
    }

    return 0;
}