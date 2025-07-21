#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], a[200005], n, m;
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] < d) continue;
        for (auto [v, w] : G[u]) {
            int cost = d + a[v] + w;
            if (cost < dis[v]) {
                dis[v] = cost;
                pq.push({cost, v});
            }
        }
    }
}

signed main() {
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
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = a[1];
    dijkstra(1);
    for (int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';
    return 0;
}