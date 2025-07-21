#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 10;

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAXN];
int vertexWeights[MAXN];

vector<long long> dijkstra(int start, int n) {
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        long long currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) continue;

        for (auto& edge : graph[current]) {
            int next = edge.to;
            long long nextDist = currentDist + edge.weight + vertexWeights[next];
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> vertexWeights[i];
        graph[i].clear();
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<long long> distances = dijkstra(1, n);

    for (int i = 2; i <= n; ++i) {
        cout << distances[i] << (i < n ? " " : "\n");
    }

    return 0;
}