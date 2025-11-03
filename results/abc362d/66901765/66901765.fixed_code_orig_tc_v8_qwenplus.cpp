#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;

void dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = a[1];
    q.push({dis[1], 1});
    
    while(!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        
        if(d > dis[u]) continue;
        
        for(auto [v, w] : G[u]) {
            int new_dist = dis[u] + w + a[v];
            if(new_dist < dis[v]) {
                dis[v] = new_dist;
                q.push({dis[v], v});
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
    
    dijkstra();
    
    for(int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << "\n";
    return 0;
}