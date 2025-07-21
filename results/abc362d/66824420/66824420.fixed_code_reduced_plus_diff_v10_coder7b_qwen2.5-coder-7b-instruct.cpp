#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = INT_MAX;

void dijkstra(const vector<vector<pair<int, int>>>& adj, const vector<int>& weights, int start, vector<ll>& dist) {
    int n = adj.size();
    dist.assign(n, INF);
    dist[start] = weights[start];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({weights[start], start});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top(); pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            ll new_dist = current_dist + weights[v] + w;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<ll> dist(n);
    dijkstra(adj, weights, 1, dist);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}