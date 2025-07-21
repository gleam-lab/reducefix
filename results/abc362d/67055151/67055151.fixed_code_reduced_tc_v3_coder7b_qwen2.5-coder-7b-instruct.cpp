#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

const int INF = 1e9;

void dijkstra(int n, vvi& adj, vi& dist, vi& parent) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (Edge& e : adj[u]) {
            int v = e.to;
            int weight = e.cost;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vvi adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    dijkstra(n, adj, dist, parent);

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + a[i] << " ";
    }
    cout << endl;

    return 0;
}