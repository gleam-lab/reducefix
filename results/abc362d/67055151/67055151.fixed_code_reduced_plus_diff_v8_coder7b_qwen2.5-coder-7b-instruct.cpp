#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    ll to, cost;
    Edge(ll to, ll cost) : to(to), cost(cost) {}
};

class Graph {
public:
    vector<vector<Edge>> adjlist;
    vector<ll> dist;

    Graph(int n) : adjlist(n), dist(n, LLONG_MAX) {}

    void addEdge(int u, int v, ll cost) {
        adjlist[u].emplace_back(v, cost);
        adjlist[v].emplace_back(u, cost);
    }

    void dijkstra(int start) {
        dist[start] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.emplace(dist[start], start);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (const auto& [v, c] : adjlist[u]) {
                if (dist[u] + c < dist[v]) {
                    dist[v] = dist[u] + c;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<ll> a(n); rep(n) cin >> a[i];

    Graph graph(n);

    rep(m) {
        ll u, v, b; cin >> u >> v >> b;
        u--, v--;
        graph.addEdge(u, v, b);
    }

    graph.dijkstra(0);

    vector<ll> costs(n - 1);
    rep(i, 1, n) {
        costs[i - 1] = graph.dist[i] + a[i];
    }

    print_container(costs);

    return 0;
}