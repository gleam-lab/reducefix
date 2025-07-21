#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int N = 200005;

int n, m;
vector<int> adj[N];
int dist[N], val[N];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n, numeric_limits<int>::max());
    dist[src] = val[src];

    pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();

        if (dist[u] < d) continue;

        for (int v : adj[u]) {
            int weight = d + val[v] + 1;  // +1 for edge weight
            if (weight < dist[v]) {
                dist[v] = weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since the graph is undirected
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << ' ';
    }
    cout << endl;

    return 0;
}