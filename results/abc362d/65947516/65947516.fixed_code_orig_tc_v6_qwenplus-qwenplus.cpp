#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli; // {cost, node}

const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli> g[N];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = a[1]; // Start with the weight of node 1
    pq.push({dis[1], 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, w] : g[u]) {
            if (dis[v] > dis[u] + w + a[v]) {
                dis[v] = dis[u] + w + a[v];
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; ++i)
        printf("%lld ", dis[i]);

    return 0;
}