#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dist[200005], dist2[200005], a[200005], n, m, vis[200005];
void dijkstra(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (vis[node]) continue;
        vis[node] = 1;
        for (auto edge : G[node]) {
            int nextNode = edge.first;
            int weight = edge.second;
            if (!vis[nextNode]) {
                pq.push({cost + a[nextNode] + weight, nextNode});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    fill(dist, dist + n + 1, 1LL << 60);
    dist[1] = a[1];
    dijkstra(1);
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}