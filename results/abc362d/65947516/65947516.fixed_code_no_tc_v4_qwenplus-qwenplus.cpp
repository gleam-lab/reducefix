#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;  // (distance, node)
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli> g[N];  // (neighbor, edge_weight)

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));  // Initialize with large values
    dis[1] = a[1];  // Start from vertex 1, include its weight

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({dis[1], 1});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, b] : g[u]) {
            if (!vis[v] && dis[v] > dis[u] + b + a[v]) {
                dis[v] = dis[u] + b + a[v];
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
        int u, v, b;
        scanf("%d%d%d", &u, &v, &b);
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }

    dijkstra();

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }

    return 0;
}