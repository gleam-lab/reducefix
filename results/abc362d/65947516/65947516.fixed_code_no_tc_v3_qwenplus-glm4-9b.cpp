#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,pair<int, ll>> piii; // Changed to store both edge weight and vertex weight
const int N=2e5+5;
int n, m;
ll a[N];
ll dist[N]; // Changed name to avoid confusion with C++ standard library function
bool visited[N];
vector<piii> g[N]; // Changed pair type to store both vertex and edge weight

void dijkstra(int start) {
    priority_queue<piii, vector<piii>, greater<piii>> q; // Max-heap to maintain the smallest distance
    memset(visited, false, sizeof(visited));
    memset(dist, LLONG_MAX, sizeof(dist)); // Initialize distances to maximum
    dist[start] = a[start]; // Start with the vertex itself
    q.push({0, start, a[start]}); // Push the start vertex with its weight

    while (!q.empty()) {
        int u = q.top().second;
        ll uDist = q.top().first;
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto &edge : g[u]) { // Iterate over all adjacent edges
            int v = edge.first;
            ll weight = edge.second;
            if (dist[u] + weight < dist[v]) { // If a shorter path is found
                dist[v] = dist[u] + weight;
                q.push({dist[v], v, a[v]}); // Push the new distance and vertex with vertex weight
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // Ensure bidirectional edges
    }

    dijkstra(1); // Run dijkstra starting from vertex 1

    for (int i = 2; i <= n; i++) {
        if (dist[i] == LLONG_MAX) puts("-1"); // If vertex i is unreachable, print -1
        else printf("%lld ", dist[i] + a[i]); // Otherwise, print the total distance including the vertex weight
    }
    return 0;
}