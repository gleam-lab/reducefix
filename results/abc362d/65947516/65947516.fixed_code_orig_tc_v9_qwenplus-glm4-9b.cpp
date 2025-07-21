#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii> g[N]; // Each element is a pair of (neighbor, edge_weight)

void heap_dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[1] = 0; // Starting from vertex 1
    priority_queue<pii, vector<pii>, greater<pii>> q; // Min-heap
    q.push({0, 1}); // Push pair of (current_weight, vertex)

    while (!q.empty()) {
        ll current_weight = q.top().first;
        int v = q.top().second;
        q.pop();

        if (vis[v]) continue;
        vis[v] = true;

        for (auto &i : g[v]) {
            ll next_v = i.first;
            ll edge_weight = i.second;

            if (dis[next_v] > current_weight + edge_weight + a[next_v]) {
                dis[next_v] = current_weight + edge_weight + a[next_v];
                q.push({dis[next_v], next_v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    heap_dijkstra();
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    return 0;
}