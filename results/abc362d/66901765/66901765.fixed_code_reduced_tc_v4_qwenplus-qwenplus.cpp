#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 9223372036854775807;

vector<vector<pair<int, int>>> G(200005);
int dis[200005], a[200005];
bool vis[200005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[start] = a[start];
    pq.push({dis[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto [v, w] : G[u]) {
            if (dis[v] > dis[u] + a[v] + w) {
                dis[v] = dis[u] + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dis[i] = INF;
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << "\n";
    
    return 0;
}