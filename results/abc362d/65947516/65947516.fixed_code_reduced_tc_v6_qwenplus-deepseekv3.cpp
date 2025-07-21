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
int n, m;
ll a[N];
ll dis[N];
vector<pli> g[N];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int i = 1; i <= n; ++i)
        dis[i] = INF;
    dis[1] = a[1];
    pq.push({dis[1], 1});
    
    while (!pq.empty()) {
        ll current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (current_dist > dis[u]) continue;
        
        for (const auto &edge : g[u]) {
            ll edge_weight = edge.first;
            int v = edge.second;
            ll new_dist = current_dist + edge_weight + a[v];
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
    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    
    dijkstra();
    
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    return 0;
}