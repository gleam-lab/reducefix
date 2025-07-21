#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f // 1e9

vector<pair<int, int>> G[200005]; // Graph adjacency list
int a[200005], n, m; // Vertex weights, number of vertices, number of edges

int dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int dist[200005]; // Distance array
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = a[start]; // Distance to the start vertex is the weight of the start vertex
    pq.push({dist[start], start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) {
            continue;
        }

        for (auto [neighbor, weight] : G[current]) {
            int nextDist = currentDist + a[neighbor] + weight;
            if (nextDist < dist[neighbor]) {
                dist[neighbor] = nextDist;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    return dist;
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    int result = dijkstra(1); // Get the minimum distance from vertex 1 to all other vertices

    for (int i = 2; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}