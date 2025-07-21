#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = LLONG_MAX / 2;

vector<pair<int,int>> G[200005];
int dis[200005], dis2[200005], a[200005], n, m, vis[200005];

void dij(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (dis[v] != d) continue;
        for (auto [w, x] : G[v]) {
            if (dis[w] > dis[v] + x + a[w]) {
                dis[w] = dis[v] + x + a[w];
                pq.push({dis[w], w});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        dis[i] = dis2[i] = INF;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dis[1] = a[1];
    dij(1);
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    cout << "\n";
    return 0;
}