#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int MAXN = 2 * 100005;

struct Edge {
    int v, w;
};

vector<Edge> adj[MAXN];
ll dist[MAXN];

void dijkstra(int start) {
    priority_queue<pli, vector<pli>, greater<>> pq;
    fill(dist, dist + MAXN, LLONG_MAX);
    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w + dist[u]) {
                dist[v] = dist[u] + w + dist[u];
                pq.emplace(dist[v], v);
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

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + dist[i] + dist[i] << " ";
    }
    cout << endl;

    return 0;
}