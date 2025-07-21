#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>

vector<pii> G[200005];
int dis[200005];
int a[200005];
int vis[200005];

void dij(int u) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({a[u], u});
    dis[u] = a[u];
    while (!q.empty()) {
        int u = q.top().second;
        int d = q.top().first;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : G[u]) {
            if (dis[v] > d + w + a[v]) {
                dis[v] = d + w + a[v];
                q.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dij(1);
    for (int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << "\n";
    return 0;
}