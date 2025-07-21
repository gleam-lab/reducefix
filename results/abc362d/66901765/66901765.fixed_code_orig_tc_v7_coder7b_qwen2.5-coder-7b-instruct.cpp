#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = LLONG_MAX / 2;

struct Edge {
    int to, w;
};

vector<Edge> G[200005];
ll dis[200005], a[200005];

void dijkstra(int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    memset(dis, 0x3f, sizeof dis);
    dis[1] = a[1];
    pq.push({a[1], 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dis[u]) continue;

        for (auto &[v, w] : G[u]) {
            if (dis[v] > d + w + a[v]) {
                dis[v] = d + w + a[v];
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%lld %lld", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dijkstra(n);

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}