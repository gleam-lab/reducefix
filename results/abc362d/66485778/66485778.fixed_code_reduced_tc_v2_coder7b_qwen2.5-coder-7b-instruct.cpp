#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e18

struct Edge {
    int u, v, w;
};

struct Node {
    int v, dist;
    bool operator<(const Node &other) const {
        return dist > other.dist;
    }
};

vector<Edge> edges;
vector<ll> dist;

void dijkstra(int n, int src) {
    priority_queue<Node> pq;
    dist.assign(n + 1, INF);
    dist[src] = 0;
    pq.push({src, 0});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int u = node.v;

        for (auto &edge : edges) {
            if (edge.u == u) {
                int v = edge.v;
                ll cost = edge.w + node.dist + dist[u];

                if (cost < dist[v]) {
                    dist[v] = cost;
                    pq.push({v, cost});
                }
            } else if (edge.v == u) {
                int v = edge.u;
                ll cost = edge.w + node.dist + dist[u];

                if (cost < dist[v]) {
                    dist[v] = cost;
                    pq.push({v, cost});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    dijkstra(n, 1);

    for (int i = 2; i <= n; i++) {
        cout << min(dist[i], (ll)a[i]) << " ";
    }
    cout << "\n";

    return 0;
}