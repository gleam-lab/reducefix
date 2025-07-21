#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], a[200005], n, m;
int INF = 1e18;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dis[1] = a[1];
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto& edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
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

    dijkstra();

    for (int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << '\n';

    return 0;
}