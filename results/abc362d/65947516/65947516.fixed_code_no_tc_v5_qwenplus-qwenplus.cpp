#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;  // First: distance, Second: node
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
vector<pli> g[N];  // Each edge stores (neighbor, weight)

void dijkstra() {
    for (int i = 1; i <= n; ++i)
        dis[i] = LLONG_MAX;
    dis[1] = a[1];  // Include A_1 as the starting point

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({dis[1], 1});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dis[u])
            continue;

        for (auto &[v, b] : g[u]) {
            ll new_dist = dis[u] + b + a[v];  // Path cost: current path cost + edge weight + destination vertex weight
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        scanf("%d%d%lld", &u, &v, &b);
        g[u].push_back({v, b});
        g[v].push_back({u, b});
    }

    dijkstra();

    for (int i = 2; i <= n; ++i)
        printf("%lld ", dis[i]);

    return 0;
}