#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;

const int MAXN = 2e5 + 5;

vector<pi> adj[MAXN];
ll dist[MAXN];
bool visited[MAXN];

void dijkstra(int start, int n) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    fill(dist, dist + n + 1, LLONG_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + v > dist[v]) {
                dist[v] = dist[u] + v;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> dist[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Run Dijkstra from vertex 1
    dijkstra(1, n);

    // Print the results
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + dist[i] + dist[i] << " ";
    }
    cout << endl;

    return 0;
}