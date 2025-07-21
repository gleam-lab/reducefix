#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct Edge {
    int to, cost;
};

vector<vector<Edge>> adjList;
vector<long long> dist;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int start) {
    fill(dist.begin(), dist.end(), LLONG_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &e : adjList[u]) {
            int v = e.to;
            int w = e.cost;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adjList.resize(n);
    dist.resize(n, LLONG_MAX);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--; // Convert to 0-based index
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    dijkstra(0); // Start from vertex 0

    for (int i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}