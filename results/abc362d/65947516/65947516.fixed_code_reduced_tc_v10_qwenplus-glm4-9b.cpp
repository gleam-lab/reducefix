#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, m;
long long a[N];
long long dis[N];
vector<pair<int, long long>> g[N]; // Each edge is represented by a pair (destination, weight)

void dijkstra(int source) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, source}); // Starting with vertex 1
    dis[source] = a[source]; // The weight of the path from 1 to 1 includes its own weight

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (dis[u] < d) continue; // Skip if we've already found a better path

        for (auto [v, weight] : g[u]) {
            long long newDis = d + weight + a[v];
            if (dis[v] > newDis) {
                dis[v] = newDis;
                q.push({newDis, v});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra(1); // Run Dijkstra's algorithm from vertex 1

    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}