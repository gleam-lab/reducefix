#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> adj(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<ll> dist(N, INF);
    dist[0] = A[0];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto [v, b] : adj[u]) {
            ll new_dist = current_dist + A[v] + b;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}