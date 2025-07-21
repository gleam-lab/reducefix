#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 200005;
vector<pair<ll, ll>> G[MAXN];
ll dist1[MAXN], dist2[MAXN];

void dijkstra(ll start, ll n) {
    fill(dist1, dist1 + n + 1, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});
    dist1[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist1[u]) continue;

        for (auto [v, w] : G[u]) {
            if (dist1[u] + w < dist1[v]) {
                dist1[v] = dist1[u] + w;
                pq.push({dist1[v], v});
            }
        }
    }
}

void reverse_dijkstra(ll start, ll n) {
    fill(dist2, dist2 + n + 1, LLONG_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, start});
    dist2[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist2[u]) continue;

        for (auto [v, w] : G[u]) {
            if (dist2[u] + w < dist2[v]) {
                dist2[v] = dist2[u] + w;
                pq.push({dist2[v], v});
            }
        }
    }
}

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);

    for (ll i = 1; i <= n; ++i) {
        scanf("%lld", &dist1[i]);
    }

    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dijkstra(1, n);
    reverse_dijkstra(1, n);

    for (ll i = 2; i <= n; ++i) {
        printf("%lld ", dist1[i] + dist2[i]);
    }
    printf("\n");

    return 0;
}