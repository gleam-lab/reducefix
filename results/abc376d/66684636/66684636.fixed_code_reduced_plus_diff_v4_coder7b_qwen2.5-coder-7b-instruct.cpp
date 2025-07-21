#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector<int> g[N];
int n, m, ans = 1e18;

void bfs() {
    queue<int> q;
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (int v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dist[i] != INT_MAX) {
            ans = min(ans, dist[i]);
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Assuming undirected graph
    }
    bfs();
    if (ans != INT_MAX) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}