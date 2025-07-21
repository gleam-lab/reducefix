#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int, int>> G[200005];
int dis[200005], a[200005], n, m;
void dij(int u){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, u});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (!dis[u]) {
            dis[u] = a[u];
            for (auto [v, w] : G[u]) {
                if (!dis[v]) q.push({dis[u] + w, v});
            }
        }
    }
}

signed main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dis, 0, sizeof dis);
    dij(1);
    for (int i = 2; i <= n; i++) cout << dis[i] << ' ';
    cout << '\n';
    return 0;
}