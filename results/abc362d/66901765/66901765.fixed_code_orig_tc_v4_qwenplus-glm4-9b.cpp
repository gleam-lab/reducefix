#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

vector<pair<int, int>> G[200005]; // Ensure this fits in memory
int dist[200005], dist2[200005], a[200005], n, m;
void dijkstra(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, u});
    while (!q.empty()) {
        int curDist = q.top().first, node = q.top().second;
        q.pop();
        if (dist[node] != -1 && dist[node] < curDist) continue; // Skip if already visited
        dist[node] = curDist;
        for (auto [v, weight] : G[node]) {
            int nextDist = curDist + weight + a[v]; // Include vertex weight in distance
            if (dist[v] > nextDist) {
                dist[v] = nextDist;
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dist, -1, sizeof(dist)); // Reset distances to -1 for unvisited nodes
    a[1] = 0; // Assuming the weight of the first vertex is 0
    dijkstra(1);
    for (int i = 2; i <= n; i++) cout << dist[i] + a[i] << ' '; // Output the total weight for each vertex
    cout << '\n';
    return 0;
}