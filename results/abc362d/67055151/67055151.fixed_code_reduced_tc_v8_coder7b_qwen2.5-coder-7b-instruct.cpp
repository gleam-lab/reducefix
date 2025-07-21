#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

struct Edge {
    ll to, cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
};

struct Node {
    ll id, dist;
    Node(ll id, ll dist) : id(id), dist(dist) {}
    bool operator>(const Node& other) const { return dist > other.dist; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    vector<vector<Edge>> graph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<ll> dist(n, LLONG_MAX);
    dist[0] = a[0];

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.emplace(0, dist[0]);

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (dist[node.id] < node.dist) continue;

        for (const Edge& edge : graph[node.id]) {
            ll next_id = edge.to;
            ll next_dist = node.dist + a[next_id] + edge.cost;
            if (next_dist < dist[next_id]) {
                dist[next_id] = next_dist;
                pq.emplace(next_id, next_dist);
            }
        }
    }

    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}