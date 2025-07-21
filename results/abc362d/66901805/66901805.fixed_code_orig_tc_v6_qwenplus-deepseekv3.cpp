#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int, int> pii;

vector<pii> G[200005];
int dis[200005];
int a[200005];
int n, m;

void dij(int u) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[u] = a[u];
    pq.push({dis[u], u});
    while (!pq.empty()) {
        int u_dist = pq.top().first;
        int u_node = pq.top().second;
        pq.pop();
        if (u_dist > dis[u_node]) continue;
        for (auto [v_node, w_edge] : G[u_node]) {
            int new_dist = u_dist + a[v_node] + w_edge;
            if (new_dist < dis[v_node]) {
                dis[v_node] = new_dist;
                pq.push({dis[v_node], v_node});
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
    fill(dis, dis + n + 1, LLONG_MAX);
    dij(1);
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}