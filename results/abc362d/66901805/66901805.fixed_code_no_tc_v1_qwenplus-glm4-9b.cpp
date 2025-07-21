#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], dis2[200005], a[200005], n, m;
void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({a[src], src});
    dis[src] = a[src];
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dis[u] != d) continue;
        for (auto &edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
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
    memset(dis, 0x3f, sizeof dis);
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';
    return 0;
}