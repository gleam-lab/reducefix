#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 1e18;

vector<pll> g[200005];
ll dist[200005];

void dijkstra(ll s, ll n) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    fill(dist, dist + n, INF);
    dist[s] = 0;
    pq.push(pll(0, s));

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : g[u]) {
            ll cost = d + w + A[v - 1];
            if (cost < dist[v]) {
                dist[v] = cost;
                pq.push(pll(cost, v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) cin >> A[i];

    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }

    dijkstra(1, n);

    for (ll i = 2; i <= n; ++i) {
        cout << dist[i] << ' ';
    }

    return 0;
}