#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e18;
vector<pair<int, int>> G[200005];
int dist[200005], vertex_weight[200005], n, m;

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = vertex_weight[source];

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            int new_dist = d + vertex_weight[v] + weight;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &vertex_weight[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}