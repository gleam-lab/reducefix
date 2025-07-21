#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 2e5 + 5;
const ll INF = LLONG_MAX;

ll a[N];
ll dis[N];
vector<pair<int, ll>> g[N];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    fill(dis, dis + N, INF);
    dis[1] = a[1];
    pq.push({dis[1], 1});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dis[u]) continue;

        for (auto &edge : g[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dis[v] > dis[u] + w + a[v]) {
                dis[v] = dis[u] + w + a[v];
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dijkstra();

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    return 0;
}