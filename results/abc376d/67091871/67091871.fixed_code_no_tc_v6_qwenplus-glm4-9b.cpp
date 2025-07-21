#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = 200005, vis[200005];
vector<int> b[200005];
vector<int> depth(200005);

void dfs(int x, int cnt) {
    vis[x] = 1;
    for (int i = 0; i < b[x].size(); i++) {
        if (!vis[b[x][i]]) {
            dfs(b[x][i], cnt + 1);
        }
    }
    depth[x] = cnt + 1; // Store depth when the dfs returns (backtracking)
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    dfs(1, 0);

    // Find the minimum depth among all nodes that are not part of any cycle
    ll minDepth = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > 0) { // If the node has been visited
            minDepth = min(minDepth, depth[i]);
        }
    }

    if (minDepth == LLONG_MAX) {
        cout << -1; // No valid node found
    } else {
        cout << minDepth;
    }

    return 0;
}