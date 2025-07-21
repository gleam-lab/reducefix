#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<vpl> vvpl;

const ll INF = 1e18;

vvpl buildGraph(int n, int m, vector<int>& a, vector<vpl>& edges) {
    vvpl graph(n);
    for (const auto& edge : edges) {
        int u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    return graph;
}

vl dijkstra(int start, vvpl& graph, const vl& a) {
    int n = graph.size();
    vl dist(n, INF);
    dist[start] = a[start];
    priority_queue<pl, vpl, greater<pl>> pq;
    pq.emplace(dist[start], start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (const auto& [v, w] : graph[u]) {
            ll nd = d + w + a[v];
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd, v);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vpl> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {u - 1, v - 1, w};
    }

    vvpl graph = buildGraph(n, m, a, edges);
    vl costs = dijkstra(0, graph, a);

    for (int i = 1; i < n; ++i) {
        cout << costs[i] << " ";
    }
    cout << endl;

    return 0;
}