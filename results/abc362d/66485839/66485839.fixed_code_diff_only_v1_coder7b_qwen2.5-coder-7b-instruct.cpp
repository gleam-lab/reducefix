#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Edge {
    int from, to, cost;
};

struct Node {
    int vertex, distance;
    bool operator<(const Node &other) const {
        return distance > other.distance;
    }
};

vector<vector<Edge>> adjList;
vector<ll> distances;

void dijkstra(int source, int n) {
    priority_queue<Node> pq;
    distances[source] = 0;
    pq.push({source, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int u = current.vertex;
        ll dist_u = current.distance;

        if (dist_u > distances[u])
            continue;

        for (auto &edge : adjList[u]) {
            int v = edge.to;
            ll dist_v = dist_u + edge.cost + distances[v];

            if (dist_v < distances[v]) {
                distances[v] = dist_v;
                pq.push({v, dist_v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1);
    distances.resize(n + 1, LLONG_MAX);

    for (int i = 1; i <= n; ++i)
        cin >> distances[i];

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({u, v, w});
        adjList[v].push_back({v, u, w});
    }

    dijkstra(1, n);

    for (int i = 2; i <= n; ++i)
        cout << distances[i] << " ";

    return 0;
}