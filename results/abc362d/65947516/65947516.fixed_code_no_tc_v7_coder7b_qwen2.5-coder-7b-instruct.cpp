#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int n, m;
ll a[N], dis[N];
bool vis[N];
vector<pair<int, int>> g[N];

struct node {
    int id;
    ll dis;
    bool operator<(const node& x) const {
        return dis > x.dis;
    }
};

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        dis[i] = LONG_LONG_MAX;
    dis[1] = 0;
    priority_queue<node> q;
    q.push({1, 0});

    while (!q.empty()) {
        node now = q.top();
        q.pop();
        if (vis[now.id]) continue;
        vis[now.id] = true;
        for (auto [neighbor, weight] : g[now.id]) {
            if (dis[neighbor] > dis[now.id] + weight + a[now.id]) {
                dis[neighbor] = dis[now.id] + weight + a[now.id];
                q.push({neighbor, dis[neighbor]});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dijkstra();

    for (int i = 2; i <= n; ++i)
        printf("%lld ", dis[i] + a[i]);

    return 0;
}