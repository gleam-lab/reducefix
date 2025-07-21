#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cost;
};

vector<vector<Edge>> adj;
vector<int> dist;

void dijkstra(int start, int n) {
    dist.resize(n, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& e : adj[u]) {
            int v = e.to;
            int weight = e.cost;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u, --v;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    vector<long long> results(n - 1);
    for (int i = 1; i < n; ++i) {
        dist.clear();
        dijkstra(0, n);
        results[i - 1] = dist[i];
    }

    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}