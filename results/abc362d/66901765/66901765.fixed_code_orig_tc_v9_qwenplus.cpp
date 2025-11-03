#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;

void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dis[start] = a[start];
    pq.push({dis[start], start});
    
    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dis[u]) continue;
        
        for(auto [v, w] : G[u]) {
            int new_dist = dis[u] + w + a[v];
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    memset(dis, 0x3f, sizeof dis);
    dijkstra(1);
    
    for(int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << "\n";
    
    return 0;
}