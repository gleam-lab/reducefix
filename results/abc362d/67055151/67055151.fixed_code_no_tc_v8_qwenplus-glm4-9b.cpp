#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge {
    ll to;
    ll weight;
};

vector<Edge> graph[200001]; // Assuming 200001 is the maximum number of vertices
ll vertex_weights[200001];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

void dijkstra(ll start) {
    fill(graph[start].begin(), graph[start].end(), Edge{});
    vector<ll> min_cost(200001, INF);
    min_cost[start] = vertex_weights[start];

    pq.push({min_cost[start], start});
    
    while (!pq.empty()) {
        auto [current_cost, u] = pq.top();
        pq.pop();

        if (current_cost > min_cost[u]) {
            continue;
        }

        for (const auto& [v, weight] : graph[u]) {
            ll next_cost = current_cost + weight + vertex_weights[v];
            if (next_cost < min_cost[v]) {
                min_cost[v] = next_cost;
                pq.push({min_cost[v], v});
            }
        }
    }

    // Output the minimum cost from vertex 1 to all other vertices except 1
    for (ll i = 2; i <= 200000; ++i) {
        cout << min_cost[i] << " ";
    }
    cout << endl;
}

int main() {
    ll N, M;
    cin >> N >> M;

    cin >> vertex_weights[1];

    for (ll i = 1; i <= N; ++i) {
        cin >> vertex_weights[i];
    }

    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    dijkstra(1);

    return 0;
}