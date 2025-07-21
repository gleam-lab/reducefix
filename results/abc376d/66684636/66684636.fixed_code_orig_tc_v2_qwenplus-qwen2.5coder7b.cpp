#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int dist[N];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] == -1) { // If not visited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    bfs(1);

    int ans = 1e18;
    for (int i = 1; i <= n; i++) {
        if (dist[i] != -1) {
            ans = min(ans, dist[i]);
        }
    }

    if (ans == 1e18) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}