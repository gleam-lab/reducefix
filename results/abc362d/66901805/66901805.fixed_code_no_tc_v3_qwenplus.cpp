#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> G[200005];
int dis[200005], a[200005];
bool vis[200005];

void dij(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[start] = a[start];
    pq.push({dis[start], start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto [v, w] : G[u]) {
            int new_dist = dis[u] + w + a[v];
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    memset(dis, 0x3f, sizeof dis);
    memset(vis, false, sizeof vis);
    
    dij(1);
    
    for (int i = 2; i <= n; i++) {
        cout << dis[i] << (i == n ? '\n' : ' ');
    }
    
    return 0;
}