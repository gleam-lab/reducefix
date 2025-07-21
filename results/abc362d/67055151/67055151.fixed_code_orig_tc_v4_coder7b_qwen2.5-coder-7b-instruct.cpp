#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int to;
    ll cost;
};

const ll INF = 1e18;

vector<ll> dijkstra(int start, vector<vector<Edge>>& graph, int n) {
    vector<ll> dist(n, INF);
    dist[start] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, c] : graph[u]) {
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        --u, --v;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<ll> costs(n - 1, INF);
    set<int> rest_nodes;
    for (int i = 0; i < n; ++i) {
        rest_nodes.insert(i);
    }

    auto cmp = [&](const tuple<int, ll, ll>& x, const tuple<int, ll, ll>& y) {
        return a[get<0>(x)] + get<1>(x) + get<2>(x) > a[get<0>(y)] + get<1>(y) + get<2>(y);
    };
    // tuple -> (current_node_num, current_edge_weight, current_cost)
    priority_queue<tuple<int, ll, ll>, vector<tuple<int, ll, ll>>, decltype(cmp)> heap(cmp);
    heap.push({0, 0, a[0]});

    while (!rest_nodes.empty()) {
        auto [current_node, current_edge, current_cost] = heap.top();
        heap.pop();

        if (!rest_nodes.count(current_node)) continue;
        rest_nodes.erase(current_node);
        if (current_node != 0) costs[current_node - 1] = current_cost;

        for (auto& [node, weight] : graph[current_node]) {
            heap.push({node, weight, current_cost + a[node] + weight});
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << costs[i] << " ";
    }
    cout << endl;

    return 0;
}