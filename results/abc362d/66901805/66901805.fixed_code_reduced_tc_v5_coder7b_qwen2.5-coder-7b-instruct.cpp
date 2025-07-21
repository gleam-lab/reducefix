#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<pair<int, int>> G[200005];
int dis[200005], a[200005], n, m;

void dij(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({a[start], start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();
        if (dist_u != dis[u]) continue;
        
        for (auto [v, w] : G[u]) {
            if (dis[v] > dist_u + a[v] + w) {
                dis[v] = dist_u + a[v] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    memset(dis, INF, sizeof dis);
    dis[1] = a[1];
    dij(1);

    for (int i = 2; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    printf("\n");

    return 0;
}