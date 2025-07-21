#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = numeric_limits<int>::max();

vector<pair<int,int>> G[200005];
int dis[200005], a[200005], n, m;

void dij(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = a[start];
    pq.push({dis[start], start});

    while (!pq.empty()) {
        auto [dist_u, u] = pq.top();
        pq.pop();
        
        if (dist_u > dis[u]) continue;
        
        for (auto [v, w] : G[u]) {
            int new_dist = dist_u + a[v] + w;
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dij(1);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i] == INF ? INT_MAX : dis[i]);
    }
    printf("\n");

    return 0;
}