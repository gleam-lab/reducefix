#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
set<int> s[200005];

void dfs(int node, int parent) {
    for (auto child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node);
        s[node].insert(s[child].begin(), s[child].end());
        s[node].insert(node);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    while (q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if (type == 2) {
            auto it = s[v].rbegin();
            advance(it, k - 1);
            if (it != s[v].rend()) cout << *it << '\n';
            else cout << "-1\n";
        } else {
            // Handle type 1 query if needed
        }
    }

    return 0;
}