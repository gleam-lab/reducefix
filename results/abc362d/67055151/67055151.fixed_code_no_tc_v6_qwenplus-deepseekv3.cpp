#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<ll> a(n); 
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; i++) {
        ll ui, vi, bi; cin >> ui >> vi >> bi;
        ui--; vi--;
        graph[ui].emplace_back(vi, bi);
        graph[vi].emplace_back(ui, bi);
    }

    vector<ll> dist(n, LLONG_MAX);
    dist[0] = a[0];

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top(); pq.pop();
        if (current_dist > dist[u]) continue;

        for (auto [v, edge_weight] : graph[u]) {
            ll new_dist = current_dist + edge_weight + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    for (ll i = 1; i < n; i++) {
        cout << dist[i] << (i == n-1 ? "\n" : " ");
    }

    return 0;
}