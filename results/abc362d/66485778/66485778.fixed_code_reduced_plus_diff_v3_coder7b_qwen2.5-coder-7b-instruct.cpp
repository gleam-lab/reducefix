#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vll;

const ll INF = LLONG_MAX / 2;

vl dijkstra(vl &dist, vll *graph, ll n, ll src) {
    priority_queue<pll, vll, greater<pll>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &[v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vl a(n+1);
    for(ll i=1;i<=n;i++)
        cin >> a[i];

    vll graph[n+1];
    for(ll i=0;i<m;i++){
        ll u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vl dist(n+1, INF);
    vl result = dijkstra(dist, graph, n, 1);

    for(ll i=2;i<=n;i++)
        cout << min(a[i], result[i]) << " ";

    return 0;
}