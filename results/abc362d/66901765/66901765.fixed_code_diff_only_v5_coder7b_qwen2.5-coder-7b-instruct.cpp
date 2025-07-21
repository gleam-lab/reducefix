#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m;
void dij(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({a[1], 1}); // Initialize the priority queue with source node and its cost
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > dis[u]) continue; // Skip outdated entries

        for (auto [v, w] : G[u]) {
            int new_dist = dist_u + a[v] + w;

            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    memset(dis, 0x3f, sizeof dis); // Initialize distance array with infinity
    dis[1] = a[1]; // Distance to the source node is zero
    dij(); // Perform Dijkstra's algorithm

    for (int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << "\n";

    return 0;
}