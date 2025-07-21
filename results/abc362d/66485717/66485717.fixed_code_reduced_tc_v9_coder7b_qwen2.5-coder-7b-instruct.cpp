#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    int node, dist;
    bool operator<(const Node &other) const {
        return dist > other.dist;
    }
};

vector<pair<int, int>> adj[200010];
ll dist[200010];

void dijkstra(int start, int n) {
    priority_queue<Node> pq;
    pq.push({start, 0});
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().node;
        ll d = pq.top().dist;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &[v, w] : adj[u]) {
            ll newDist = d + w + v; // Add the weight of the vertex v
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({v, newDist});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> dist[i]; // Initialize the distance array with vertex weights
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1, n);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}