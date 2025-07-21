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
vector<pli> g[N];

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        dis[i] = LONG_LONG_MAX;
    }
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1}); // Start from vertex 1 with distance 0

    while (!pq.empty()) {
        pli now = pq.top();
        pq.pop();
        if (vis[now.second]) continue;
        vis[now.second] = true;

        for (auto& edge : g[now.second]) {
            int next = edge.second;
            ll weight = edge.first;

            if (dis[next] > dis[now.second] + weight) {
                dis[next] = dis[now.second] + weight;
                pq.push({dis[next], next});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    dijkstra();

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i] + a[i]);
    }
    printf("\n");

    return 0;
}