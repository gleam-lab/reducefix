#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll INF = 1e18;

vector<ll> adj[200001]; // Graph adjacency list
ll weights[200001]; // Vertex weights

void dijkstra(ll start, vector<ll>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist.assign(200001, INF);
    dist[start] = weights[start];
    pq.push({dist[start], start});

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, w] : adj[u]) {
            ll next_dist = d + w + weights[v];
            if (next_dist < dist[v]) {
                dist[v] = next_dist;
                pq.push({next_dist, v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> weights[i];

    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<ll> dist;
    dijkstra(1, dist);

    for (ll i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}