#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF LLONG_MAX

struct Edge {
    int u, v, w;
};

struct Node {
    int node, dist;
    bool operator<(const Node &other) const {
        return dist > other.dist;
    }
};

void dijkstra(vector<vector<pair<int, int>>> &graph, vector<ll> &dist, int start) {
    priority_queue<Node> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.node;
        int d = current.dist;

        if (d > dist[u]) continue;

        for (auto neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<ll> dist(n + 1, INF);
    dijkstra(graph, dist, 1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << endl;

    return 0;
}