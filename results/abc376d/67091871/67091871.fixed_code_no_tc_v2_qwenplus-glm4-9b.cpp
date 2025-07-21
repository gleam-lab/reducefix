#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = 200005, ans = 1;
vector<int> adj[200005];
bool visited[200005] = {false};

void dfs(int node, int depth) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, depth + 1);
            ans = max(ans, depth + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Find the starting node with at least one unvisited neighbor
    bool hasUnvisited = false;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 0 && !visited[i]) {
            hasUnvisited = true;
            dfs(i, 1);
            break;
        }
    }

    if (!hasUnvisited || ans == 1) {
        cout << -1;
    } else {
        cout << ans - 1; // Subtract 1 because the depth was incremented at the start
    }
    return 0;
}