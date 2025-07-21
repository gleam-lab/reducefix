#include <bits/stdc++.h>
using namespace std;
#define int long long
template <typename T>
struct MinCostFlow {
    int n, m;
    vector<vector<pair<int, T>>> adj;
    vector<T> dist, flow;
    vector<int> prev, prev_e;
    MinCostFlow(int n) : n(n), adj(n), dist(n), flow(n), prev(n), prev_e(n) {}

    void add_edge(int from, int to, T cap, T cost) {
        adj[from].push_back({to, cost, cap});
        adj[to].push_back({from, -cost, 0}); // Add reverse edge with 0 capacity
    }

    bool bellman_ford(int src, intdst, T &total_cost) {
        fill(dist.begin(), dist.end(), numeric_limits<T>::max());
        dist[src] = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int u = 0; u < n; ++u) {
                for (auto &edge : adj[u]) {
                    if (edge.second > 0 && dist[u] != numeric_limits<T>::max() && dist[u] + edge.second < dist[edge.first]) {
                        dist[edge.first] = dist[u] + edge.second;
                        prev[edge.first] = u;
                        prev_e[edge.first] = edge.first;
                    }
                }
            }
        }
        // Check for negative-weight cycle
        for (int u = 0; u < n; ++u) {
            for (auto &edge : adj[u]) {
                if (edge.second > 0 && dist[u] != numeric_limits<T>::max() && dist[u] + edge.second < dist[edge.first]) {
                    return false; // Negative weight cycle detected
                }
            }
        }
        return true;
    }

    T push_relabel(int src, int dst, T flow, T &cost) {
        if (flow == 0) return 0;
        T pushed = 0, cost_of_p = 0;
        int v = src;
        while (flow && v != dst) {
            T pushed_i = min(flow, (dist[v] != numeric_limits<T>::max()) ? (dist[v] - dist[prev[v]]) : numeric_limits<T>::max());
            for (int i = 0; i < adj[v].size() && pushed_i; ++i) {
                auto &edge = adj[v][i];
                if (edge.second > 0 && dist[v] != numeric_limits<T>::max() && dist[v] + edge.second < dist[edge.first]) {
                    pushed_i = min(pushed_i, edge.second);
                }
            }
            for (int i = 0; i < adj[v].size() && pushed_i; ++i) {
                auto &edge = adj[v][i];
                if (edge.second > 0 && dist[v] != numeric_limits<T>::max() && dist[v] + edge.second < dist[edge.first]) {
                    edge.second -= pushed_i;
                    flow -= pushed_i;
                    if (edge.second == 0) {
                        dist[edge.first] = numeric_limits<T>::max();
                    } else {
                        dist[edge.first] = dist[v] + edge.second;
                    }
                    prev_e[edge.first] = i;
                    pushed += pushed_i;
                    cost_of_p += pushed_i * edge.first;
                }
            }
        }
        return cost_of_p;
    }

    T min_cost_flow(int src, int dst, T flow) {
        T total_cost = 0;
        while (flow > 0) {
            if (!bellman_ford(src, dst, dist)) {
                return -1; // Negative cycle found
            }
            T pushed = push_relabel(src, dst, flow, total_cost);
            if (pushed == 0) return total_cost; // No more flow
        }
        return total_cost;
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    MinCostFlow<int> mcf(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        mcf.add_edge(u, v, 1, w);
    }
    mcf.add_edge(0, 1, n, 0); // Add edges from source to all nodes except sink
    mcf.add_edge(n + 1, 1, n - 1, -a[1]); // Add edges from sink to all nodes with negative cost (vertex weights)

    for (int i = 2; i <= n; ++i) {
        mcf.add_edge(n + 1, i, 1, 0); // Add edges to all nodes from sink with zero cost
    }

    T result = mcf.min_cost_flow(0, n + 1, n - 1);
    if (result == -1) {
        cout << "Negative cycle detected\n";
    } else {
        cout << result << "\n";
    }
    return 0;
}