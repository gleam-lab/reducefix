#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = LLONG_MAX;

struct Edge {
    int v, w;
};

vector<Edge> G[200005];
ll dis[200005], a[200005], n, m;

void dij(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({a[s], s});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > dis[u]) continue;
        for (auto& e : G[u]) {
            int v = e.v, w = e.w;
            if (dis[u] + a[v] + w < dis[v]) {
                dis[v] = dis[u] + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dis, 0x3f, sizeof dis);
    dis[1] = a[1];
    dij(1);
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    return 0;
}