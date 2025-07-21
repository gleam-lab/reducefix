#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dist[200005], dist2[200005], a[200005], n, m, visited[200005];
void dijkstra(int u){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto [v, w] : G[u]) {
            if (!visited[v]) {
                dist[v] = dist[u] + a[v] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = a[1];
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}