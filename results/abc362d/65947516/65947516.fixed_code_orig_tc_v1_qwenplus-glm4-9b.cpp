#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dist[N]; // dist[i] represents the minimum weight of path from 1 to i
bool vis[N];
vector<pii> adj[N]; // adjacency list to represent the graph

struct node {
    int id, dis;
    bool operator<(const node& x)const {
        return dis > x.dis;
    }
};

void dijkstra(int start) {
    priority_queue<node> pq;
    memset(vis, 0, sizeof(vis)); // Initialize visited array
    memset(dist, LLONG_MAX, sizeof(dist)); // Initialize distances to infinity
    dist[start] = a[start]; // Distance of starting point is its own weight
    pq.push({start, dist[start]});
    
    while (!pq.empty()) {
        int u = pq.top().id;
        pq.pop();
        
        if (vis[u]) continue; // Ignore if vertex is already visited
        vis[u] = 1;
        
        for (auto& [v, w] : adj[u]) {
            ll alt = dist[u] + a[v] + w; // Alternative cost of reaching v via u
            
            if (!vis[v] && alt < dist[v]) { // If v is unvisited and path is shorter, update and push
                dist[v] = alt;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        adj[i].reserve(n); // Make sure each adjacency list has enough space for edges
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // Run Dijkstra's algorithm from vertex 1
    dijkstra(1);
    
    // Output the minimum weight path for vertices 2 to N
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dist[i] + a[i]);
    }
    printf("\n");
    
    return 0;
}