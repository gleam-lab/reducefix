#include<bits/stdc++.h>
using namespace std;

const int INF = 1e18;
const int MAXN = 2 * 100005;

vector<pair<int, int>> G[MAXN];
long long dis[MAXN], a[MAXN], n, m;

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({a[start], start});
    
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        
        if (dist > dis[u]) continue;
        
        for (auto [v, w] : G[u]) {
            long long new_dist = dist + a[v] + w;
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
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

    memset(dis, INF, sizeof(dis));
    dis[1] = a[1];
    dijkstra(1);

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");

    return 0;
}