#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int INF = 0x3f3f3f3f;
vector<pair<ll,ll>>G[200005];
ll dis[200005],a[200005],n,m;

void dij(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    memset(dis, INF, sizeof(dis));
    dis[s] = a[s];
    pq.push({dis[s], s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dis[u]) continue;
        for (auto [v, w] : G[u]) {
            if (dis[v] > d + a[v] + w) {
                dis[v] = d + a[v] + w;
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
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}