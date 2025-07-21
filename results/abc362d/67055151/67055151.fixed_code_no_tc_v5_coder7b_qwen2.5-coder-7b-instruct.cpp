#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int start, vector<vector<pii>>& adjList, vector<long long>& dist, vector<long long>& cost) {
    int n = adjList.size();
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < pq.top().first) continue;

        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cost[v] = cost[u] + w;
                pq.push({dist[v], v});
            } else if (dist[u] + w == dist[v]) {
                cost[v] = min(cost[v], cost[u] + w);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<pii>> adjList(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v; // Adjusting for 0-based indexing
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    vector<long long> dist(n, LLONG_MAX);
    vector<long long> cost(n, LLONG_MAX);

    dijkstra(0, adjList, dist, cost);

    for (int i = 1; i < n; ++i) {
        cout << cost[i] << " ";
    }
    cout << endl;

    return 0;
}