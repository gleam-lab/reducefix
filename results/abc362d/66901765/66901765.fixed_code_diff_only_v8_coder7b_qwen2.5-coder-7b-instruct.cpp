#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;
bool vis[200005];

// Function to perform Dijkstra's Algorithm
void dij(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({a[start], start});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : G[u]) {
            if (dis[v] > dist + a[v] + w) {
                dis[v] = dist + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = a[1];
    dij(1);

    for (int i = 2; i <= n; ++i) {
        cout << dis[i] << ' ';
    }
    cout << '\n';

    return 0;
}