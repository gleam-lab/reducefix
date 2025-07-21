#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> G[200005];
int dis[200005];
int a[200005];
bool vis[200005];

void dij(int u) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({a[u], u});
    dis[u] = a[u];
    while (!q.empty()) {
        int current = q.top().second;
        int current_dis = q.top().first;
        q.pop();
        if (vis[current]) continue;
        vis[current] = true;
        for (auto [v, w] : G[current]) {
            if (dis[v] > current_dis + a[v] + w) {
                dis[v] = current_dis + a[v] + w;
                q.push({dis[v], v});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    memset(dis, 0x3f, sizeof dis);
    memset(vis, false, sizeof vis);
    dij(1);
    for (int i = 2; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    cout << "\n";
    return 0;
}