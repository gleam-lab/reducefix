#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>

vector<pair<int,int>> G[200005];
int dis[200005], a[200005];
bool vis[200005];

void dij(int u) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dis[u] = 0;
    q.push({dis[u], u});
    
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        
        if(vis[u]) continue;
        vis[u] = true;
        
        for(auto [v, w] : G[u]) {
            if(dis[v] > dis[u] + w + a[v]) {
                dis[v] = dis[u] + w + a[v];
                q.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    fill(dis, dis + n + 1, LLONG_MAX);
    fill(vis, vis + n + 1, false);
    
    dij(1);
    
    for(int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}