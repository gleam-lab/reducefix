#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e18;

vector<pair<int,int>> G[200005];
int dist[200005];
int a[200005];
bool vis[200005];

void dijkstra(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[u] = a[u];
    pq.push({dist[u], u});
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : G[u]) {
            if (dist[v] > current_dist + w + a[v]) {
                dist[v] = current_dist + w + a[v];
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
    fill(dist, dist + n + 1, INF);
    dist[1] = a[1];
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}