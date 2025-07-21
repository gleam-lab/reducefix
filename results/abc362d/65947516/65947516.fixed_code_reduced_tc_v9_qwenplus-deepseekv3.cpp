#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
vector<pair<int, ll>> g[N];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int i = 1; i <= n; ++i) {
        dis[i] = LLONG_MAX;
    }
    dis[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        ll current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (current_dist > dis[u]) continue;
        
        for (auto &edge : g[u]) {
            int v = edge.first;
            ll cost = edge.second;
            ll new_dist = current_dist + cost + a[v];
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
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
    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    dijkstra();
    
    for (int i = 2; i <= n; ++i) {
        if (dis[i] == LLONG_MAX) {
            printf("9223372036854775807 ");
        } else {
            printf("%lld ", dis[i]);
        }
    }
    printf("\n");
    return 0;
}