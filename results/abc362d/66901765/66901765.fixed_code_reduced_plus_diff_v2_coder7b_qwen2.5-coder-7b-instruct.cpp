#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> G[200005];
ll dis[200005],dis2[200005],a[200005],n,m,vis[200005];

// Function to perform Dijkstra's algorithm
void dijkstra(int start) {
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,start});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : G[u]) {
            if (dis[v] > dist + a[v] + w) {
                dis[v] = dist + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // Read input
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    // Initialize distances to infinity
    fill(dis, dis+n+1, LLONG_MAX);

    // Run Dijkstra's algorithm from node 1
    dijkstra(1);

    // Print results for nodes 2 through n
    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    return 0;
}