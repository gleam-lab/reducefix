#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll INF = 1e18;

vector<pair<ll,ll>> G[200005];
ll dis[200005], a[200005], n, m;

void dij(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    memset(dis, 0x3f, sizeof dis);
    dis[start] = a[start];
    pq.push({dis[start], start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dis[u]) continue;

        for (auto [v, w] : G[u]) {
            ll new_dis = d + a[v] + w;
            if (new_dis < dis[v]) {
                dis[v] = new_dis;
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

    dij(1);

    for (int i = 2; i <= n; i++) {
        if (dis[i] == INF) printf("INF ");
        else printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}