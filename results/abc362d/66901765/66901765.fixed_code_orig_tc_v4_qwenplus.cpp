#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;
bool vis[200005];

void dij(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dis[start] = a[start];
    pq.push({dis[start], start});
    
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for(auto [v, w] : G[u]) {
            int new_cost = d + w + a[v];
            if (new_cost < dis[v]) {
                dis[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dis[i] = LLONG_MAX;
    }
    
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dij(1);
    
    for(int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}