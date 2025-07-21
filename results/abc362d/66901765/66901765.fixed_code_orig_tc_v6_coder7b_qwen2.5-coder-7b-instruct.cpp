#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],dis2[200005],a[200005],n,m,vis[200005];
void dij(int u){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({a[u], u});
    while (!q.empty()) {
        auto [dist, v] = q.top();
        q.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        for (auto [u, w] : G[v]) {
            if (dis2[u] > dist + a[u] + w) {
                dis2[u] = dist + a[u] + w;
                q.push({dis2[u], u});
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
    memset(dis2, 0x3f, sizeof dis2);
    for (int i = 1; i <= n; i++) {
        dis2[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        dij(i);
    }
    for (int i = 2; i <= n; i++) {
        cout << dis2[i] << " ";
    }
    return 0;
}