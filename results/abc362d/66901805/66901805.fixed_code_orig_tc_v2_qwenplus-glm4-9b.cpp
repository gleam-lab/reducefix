#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define int long long

vector<pair<int, int>> G[200005];
int n, m;
int dist[200005];

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[current]) {
            continue;
        }

        for (auto &edge : G[current]) {
            int next = edge.first;
            int weight = edge.second + G[next][0].second; // assuming an initial edge weight of A[next]
            
            if (dist[next] > currentDist + weight) {
                dist[next] = currentDist + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    // Initialize distances with INF
    fill(dist, dist + n + 1, INF);

    // Run Dijkstra's algorithm from vertex 1
    dijkstra(1);

    // Output the shortest path distances considering vertex weights
    for (int i = 2; i <= n; i++) {
        cout << (dist[i] - G[i][0].second) << ' '; // Subtract vertex weight A[i] from the path weight
    }
    cout << '\n';

    return 0;
}