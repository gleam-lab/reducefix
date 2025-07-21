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
ll dist[N];
vector<pii> graph[N]; // Changed from g[N] to graph[N] for clarity

void dijkstra() {
    memset(dist, LLONG_MAX, sizeof(dist));
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1}); // Start with vertex 1 and distance 0

    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.first;
            ll weight = edge.second + a[u]; // Total weight including vertex weight

            if (dist[v] > d + weight) {
                dist[v] = d + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; i++) {
        printf("%lld ", dist[i] + a[i]); // Include vertex weight in path weight
    }
    printf("\n");

    return 0;
}