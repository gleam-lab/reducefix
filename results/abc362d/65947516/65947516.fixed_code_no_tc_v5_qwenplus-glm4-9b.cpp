#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
ll a[N];
ll dis[N];
vector<pii> g[N]; // Using vector instead of list for potentially better cache performance

void dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Max-heap for storing vertices and their current distance
    memset(dis, LLONG_MAX, sizeof(dis)); // Initialize distances to a large number
    dis[src] = 0;
    pq.push({0, src}); // Push the source with 0 distance

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dis[u]) continue; // Skip if the popped distance is not the shortest

        for (auto &edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dis[v] > d + weight + a[v]) { // Calculate cost to v through u
                dis[v] = d + weight + a[v];
                pq.push({dis[v], v}); // Push v with the new distance
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra(1); // Compute shortest paths from vertex 1 to all other vertices

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    return 0;
}