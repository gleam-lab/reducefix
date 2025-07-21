#include<bits/stdc++.h>
using namespace std;

#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], dis2[200005], a[200005], n, m, vis[200005];

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

void dij(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({s, a[s]});
    memset(vis, 0, sizeof(vis));
    while (!pq.empty()) {
        auto [u, dist] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : G[u]) {
            if (dis[v] > dist + a[v] + w) {
                dis[v] = dist + a[v] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        dis[i] = INT_MAX;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dis[1] = a[1];
    dij(1);
    for (int i = 2; i <= n; i++) {
        cout << min(dis[i], dis2[i]) << " ";
    }
    cout << "\n";
    return 0;
}