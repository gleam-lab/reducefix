#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

struct Edge {
    int to;
    ll cost;
};

struct Node {
    int vertex;
    ll distance;
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<ll> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[1] = a[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        int u = current.vertex;
        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : adj[u]) {
            int v = edge.to;
            ll cost = edge.cost;
            if (dist[v] > dist[u] + cost + a[v]) {
                dist[v] = dist[u] + cost + a[v];
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}