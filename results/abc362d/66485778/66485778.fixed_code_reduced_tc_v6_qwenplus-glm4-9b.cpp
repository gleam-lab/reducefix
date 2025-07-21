#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back

using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;

struct Edge {
    int to, cost, rev;
    bool operator < (const Edge& other) const {
        return cost > other.cost;
    }
};

int n, m;
VV edges(n + 1, V<int>(3));
V long long dist(n + 1, LLONG_MAX), vertex_wt(n + 1);
V<bool> visited(n + 1, false);

void compute_min_weights() {
    priority_queue<Edge> pq;
    pq.push({1, vertex_wt[1], 0});
    dist[1] = vertex_wt[1];
    visited[1] = true;

    while (!pq.empty()) {
        auto [u, cost, _] = pq.top();
        pq.pop();

        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i][0];
            int weight = edges[u][i][1];
            int edge_cost = edges[u][i][2];

            long long new_cost = cost + weight + edge_cost;

            if (dist[v] > new_cost) {
                dist[v] = new_cost;
                pq.push({v, new_cost, 0});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    vertex_wt[1] = cin.get(); // Read the first vertex weight as a character and convert to int
    for (int i = 2; i <= n; ++i) {
        vertex_wt[i] = cin.get();
        if (cin.peek() == ' ') cin.ignore(); // Skip spaces
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].pb({v, vertex_wt[v], c});
        edges[v].pb({u, vertex_wt[u], c});
    }

    compute_min_weights();

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}