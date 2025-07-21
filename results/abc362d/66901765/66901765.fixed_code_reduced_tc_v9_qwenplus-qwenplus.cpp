#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 9223372036854775807;

vector<vector<pair<int, int>>> G(200005); // {to, weight}
int dis[200005];
int a[200005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[start] = a[start];
    pq.push({dis[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        
        if (current_dist > dis[u]) continue;
        
        for (auto [v, w] : G[u]) {
            int new_dist = dis[u] + w + a[v]; // path weight: current path sum + edge weight + next vertex weight
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
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dis[i] = INF;
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << " ";
    }
    cout << "\n";
    
    return 0;
}