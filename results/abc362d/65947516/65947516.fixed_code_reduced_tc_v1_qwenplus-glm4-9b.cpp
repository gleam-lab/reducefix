#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 2e5 + 5;

struct Edge {
    int to;
    long long weight;
};

long long n, m;
long long A[N];
vector<Edge> graph[N];
long long dist[N];

void dijkstra(int source) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({A[source], source});
    dist[source] = A[source];

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] < d) continue;

        for (auto &edge : graph[u]) {
            int v = edge.to;
            long long weight = edge.weight;
            long long newDist = d + weight + A[v];

            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}