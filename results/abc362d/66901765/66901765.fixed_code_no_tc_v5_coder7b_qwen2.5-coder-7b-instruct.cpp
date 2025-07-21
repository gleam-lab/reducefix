#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
vector<pair<ll,ll>> G[200005];
ll dis[200005], a[200005], n, m;

// Function to perform Dijkstra's algorithm
void dijkstra(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});
    dis[start] = a[start];

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        
        // If already visited or a better distance has been found, skip
        if (dist > dis[u]) continue;
        
        for (auto [v, w] : G[u]) {
            ll new_dist = dist + a[v] + w;
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({new_dist, v});
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

    // Initialize distances to infinity
    memset(dis, 0x3f, sizeof dis);
    dis[1] = a[1];

    // Perform Dijkstra's algorithm starting from vertex 1
    dijkstra(1);

    // Print the results for vertices 2 to n
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}