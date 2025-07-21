#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1e18;
vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;

void dij(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({a[u], u});
    dis[u] = a[u];
    while (!q.empty()) {
        int current_dist = q.top().first;
        int u = q.top().second;
        q.pop();
        if (current_dist > dis[u]) continue;
        for (auto [v, w] : G[u]) {
            int new_dist = current_dist + a[v] + w;
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                q.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
    }
    dij(1);
    for (int i = 2; i <= n; i++) {
        if (dis[i] == INF) {
            cout << "-1 ";
        } else {
            cout << dis[i] << ' ';
        }
    }
    cout << "\n";
    return 0;
}