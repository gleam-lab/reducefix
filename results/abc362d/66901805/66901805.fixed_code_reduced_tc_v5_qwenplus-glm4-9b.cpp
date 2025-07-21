#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>>G[200005];
int dist[200005], a[200005], n, m;
void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty()) {
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d != dist[v]) continue;
        for (auto edge : G[v]) {
            int to = edge.first;
            int weight = edge.second;
            if (dist[to] > d + weight + a[to]) {
                dist[to] = d + weight + a[to];
                pq.push({dist[to], to});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dist, 0x3f, sizeof(dist));
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}