#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// Define the maximum number of nodes and edges
const int MAXN = 2e5 + 5;

// Adjacency list to store the graph
vector<pair<ll, ll>> G[MAXN];

// Arrays to store distances and visited status
ll dis[MAXN], a[MAXN], n, m;
bool vis[MAXN];

// Function to perform Dijkstra's algorithm from a given source node
void dij(int u) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, u});
    dis[u] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        
        if (d > dis[u]) continue; // Skip outdated entries
        
        if (!vis[u]) {
            vis[u] = true;
            for (auto [v, w] : G[u]) {
                ll new_dist = d + a[v] + w;
                if (new_dist < dis[v]) {
                    dis[v] = new_dist;
                    pq.push({dis[v], v});
                }
            }
        }
    }
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
    
    memset(dis, 0x3f, sizeof dis); // Initialize distance array with infinity
    dis[1] = a[1]; // Distance to start node is its own value
    
    dij(1); // Perform Dijkstra's algorithm from node 1
    
    // Print results for nodes 2 to n
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    
    return 0;
}