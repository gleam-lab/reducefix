#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define endl "\n"
#define int long long

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int depth[MAXN];
bool visited[MAXN];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    depth[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                depth[v] = depth[u] + 1;
                q.push(v);
            } else if (depth[v] != 0) {
                // Found a back edge to node 1 indirectly
                // Update the minimum cycle length involving node 1
                depth[v] = min(depth[v], depth[u] + 1);
            }
        }
    }

    if (depth[1] == 0 || depth[1] == LLONG_MAX) {
        cout << -1;
    } else {
        cout << depth[1];
    }
}

signed main() {
    IOS;
    solve();
    return 0;
}