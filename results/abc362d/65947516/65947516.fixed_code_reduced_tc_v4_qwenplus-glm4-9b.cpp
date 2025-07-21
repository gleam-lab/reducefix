#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii> g[N];

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1}); // Push the initial vertex with 0 cost

    while (!q.empty()) {
        auto [cost, u] = q.top();
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &edge : g[u]) {
            int v = edge.first;
            ll weight = edge.second + a[u];

            if (dis[u] != LLONG_MAX && dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i] == LLONG_MAX ? 0 : dis[i]);
    }
    return 0;
}