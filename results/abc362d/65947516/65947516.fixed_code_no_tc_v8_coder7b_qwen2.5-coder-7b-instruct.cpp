#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<int,int>> piii; // Change data type to store cumulative weight
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pair<int,ll>> g[N]; // Corrected data type for storing weights in adjacency list

void dijkstra() {
    memset(vis, false, sizeof(vis));
    priority_queue<piii, vector<piii>, greater<piii>> pq; // Min-heap based priority queue
    pq.push({a[1], {1, 0}}); // Initialize with starting vertex and its cumulative weight

    while (!pq.empty()) {
        auto [currentWeight, current] = pq.top(); // Extract the minimum element
        pq.pop();

        int u = current.first;
        ll distFromStart = current.second;

        if (vis[u]) continue;
        vis[u] = true;

        dis[u] = distFromStart + a[u]; // Update distance

        for (auto [v, w]: g[u]) {
            if (distFromStart + w < dis[v]) {
                dis[v] = distFromStart + w; // Relaxation step
                pq.push({dis[v], {v, distFromStart + w}});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra();
    
    for (int i = 2; i <= n; i++)
        printf("%lld ", dis[i]);

    return 0;
}