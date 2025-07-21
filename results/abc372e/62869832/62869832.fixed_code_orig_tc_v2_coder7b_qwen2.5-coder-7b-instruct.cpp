#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];

void dfs(int node, int par) {
    for(auto child : adj[node]) {
        if(child != par) {
            dfs(child, node);
            adj[node].insert(adj[node].end(), adj[child].begin(), adj[child].end());
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> ans(n + 1);
    vector<bool> vis(n + 1, false);

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            int v, k;
            cin >> v >> k;
            sort(adj[v].begin(), adj[v].end(), greater<int>());
            adj[v].erase(unique(adj[v].begin(), adj[v].end()), adj[v].end());
            if(k <= adj[v].size()) cout << adj[v][k - 1] << '\n';
            else cout << "-1\n";
        }
    }

    return 0;
}