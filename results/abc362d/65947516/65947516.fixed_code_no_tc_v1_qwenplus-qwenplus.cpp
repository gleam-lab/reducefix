#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const int N = 2e5 + 5;
int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli> g[N]; // {to, cost}

void dijkstra() {
    fill(dis, dis + n + 1, LLONG_MAX);
    memset(vis, false, sizeof(vis));
    dis[1] = a[1]; // Include A_1 as part of starting point
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({dis[1], 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, b] : g[u]) {
            ll new_cost = d + b + a[v]; // Add edge weight and destination vertex weight
            if (new_cost < dis[v]) {
                dis[v] = new_cost;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }

    return 0;
}