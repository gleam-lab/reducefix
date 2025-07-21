#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = LLONG_MAX / 2;

struct Edge {
    ll v, w;
};

class Graph {
public:
    vector<Edge> *adjList;
    ll n;

    Graph(ll n) {
        this->n = n;
        adjList = new vector<Edge>[n + 1];
    }

    void addEdge(ll u, ll v, ll w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
};

void dijkstra(Graph &graph, ll s, ll *dist) {
    priority_queue<pll, vector<pll>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph.adjList[u]) {
            ll v = edge.v;
            ll weight = edge.w;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), dist(n + 1, INF);
    
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    Graph graph(n);

    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        graph.addEdge(u, v, b);
    }

    dijkstra(graph, 1, dist);

    for (ll i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }

    return 0;
}