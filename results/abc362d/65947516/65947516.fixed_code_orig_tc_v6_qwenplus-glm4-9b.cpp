#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii; // Using ll for the second value to handle large weights
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii> g[N]; // Adjacency list with weights

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q; // Min-heap
    q.push({0, 1}); // Start with vertex 1 and cost 0

    while (!q.empty()) {
        auto [cost, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : g[u]) {
            ll new_cost = dis[u] + a[u] + w;
            if (dis[v] > new_cost) {
                dis[v] = new_cost;
                q.push({new_cost, v});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dijkstra();
    for (int i = 2; i <= n; i++)
        printf("%lld ", dis[i]);
    return 0;
}