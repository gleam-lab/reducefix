#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<pair<ll,ll>>G[200005];
ll dis[200005],a[200005],n,m;

// Function to perform Dijkstra's algorithm
void dij(int s){
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    fill(dis, dis + n + 1, LLONG_MAX); // Initialize distances to infinity
    dis[s] = a[s]; // Distance from source to itself is its own weight
    pq.push({dis[s], s}); // Push source node into priority queue
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); // Get the smallest distance node
        pq.pop();
        
        if (dist > dis[u]) continue; // If the popped distance is greater than current known distance, skip
        
        for (auto [v, w] : G[u]) { // Traverse all adjacent nodes
            if (dis[v] > dis[u] + w + a[v]) { // Relaxation step
                dis[v] = dis[u] + w + a[v];
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]); // Read vertex weights
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w); // Read edge details
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dij(1); // Perform Dijkstra's from source vertex 1
    
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]); // Print the minimum distance to each vertex
    }
    cout << "\n";
    return 0;
}