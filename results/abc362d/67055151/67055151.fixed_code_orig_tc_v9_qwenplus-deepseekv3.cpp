#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    vector<ll> dist(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[0] = a[0];
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        ll current_dist = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto &[v, b] : graph[u]) {
            ll new_dist = current_dist + a[v] + b;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}