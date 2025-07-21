#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e18;

vector<pair<int,int>> G[200005];
int dis[200005];
int a[200005];
int n, m;

void dijkstra(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[u] = a[u];
    pq.push({dis[u], u});
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (current_dist > dis[u]) continue;
        for (auto [v, w] : G[u]) {
            int new_dist = current_dist + a[v] + w;
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
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
    fill(dis, dis + n + 1, INF);
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        cout << (dis[i] == INF ? -1 : dis[i]) << ' ';
    }
    cout << '\n';
    return 0;
}