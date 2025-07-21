#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e18;
vector<pair<int,int>> G[200005];
int dis[200005];
int a[200005];
int n, m;

void dij(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({a[u], u});
    dis[u] = a[u];
    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (current_dist > dis[u]) continue;
        for (auto [v, w] : G[u]) {
            if (dis[v] > dis[u] + a[v] + w) {
                dis[v] = dis[u] + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    fill(dis, dis + n + 1, INF);
    dij(1);
    for(int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}