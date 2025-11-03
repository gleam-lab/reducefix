#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;
bool vis[200005];

void dij(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dis[u] = a[u];
    pq.push({dis[u], u});
    
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if(vis[u]) continue;
        vis[u] = true;
        
        for(auto [v, w] : G[u]) {
            if(dis[v] > dis[u] + w + a[v]) {
                dis[v] = dis[u] + w + a[v];
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
    dij(1);
    
    for(int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << "\n";
    
    return 0;
}