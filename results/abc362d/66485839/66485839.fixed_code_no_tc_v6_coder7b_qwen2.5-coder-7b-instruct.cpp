#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 10;
const ll INF = 1e18;

struct Edge {
    int u, v, w;
};

struct CompareEdge {
    bool operator()(const Edge &a, const Edge &b) {
        return a.w > b.w;
    }
};

vector<Edge> edges;
vector<ll> dist(MAXN, INF);

void dijkstra(int n, int src) {
    priority_queue<Edge, vector<Edge>, CompareEdge> pq;
    pq.push({src, src, 0});
    dist[src] = 0;

    while (!pq.empty()) {
        Edge current = pq.top();
        pq.pop();

        int u = current.u;
        int v = current.v;
        ll weight = current.w;

        if (weight > dist[u])
            continue;

        for (auto &edge : edges) {
            if (edge.u == u && edge.v == v) {
                int next_u = edge.v;
                int next_v = edge.u;
                ll next_weight = edge.w;

                if (dist[next_u] > dist[u] + next_weight) {
                    dist[next_u] = dist[u] + next_weight;
                    pq.push({next_u, next_v, dist[next_u]});
                }
                if (dist[next_v] > dist[u] + next_weight) {
                    dist[next_v] = dist[u] + next_weight;
                    pq.push({next_v, next_u, dist[next_v]});
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

    vector<int> weights(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }

    dijkstra(n, 1);

    for (int i = 2; i <= n; i++) {
        cout << dist[i] + weights[i] << " ";
    }
    cout << endl;

    return 0;
}