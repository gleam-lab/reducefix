#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli; // Change pair type to store distance first
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli>g[N]; // Change vector element type to store distance first

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for(int i=1; i<=n; i++) dis[i] = LONG_LONG_MAX;
    dis[1] = 0;

    priority_queue<pli, vector<pli>, greater<pli>> pq; // Use min-heap for Dijkstra's algorithm
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [current_dist, current_node] = pq.top(); // Use structured binding
        pq.pop();

        if(vis[current_node]) continue;
        vis[current_node] = true;

        for(auto [neighbor, edge_weight]: g[current_node]) {
            if(dis[neighbor] > current_dist + edge_weight + a[neighbor]) {
                dis[neighbor] = current_dist + edge_weight + a[neighbor];
                pq.push({dis[neighbor], neighbor}); // Push updated distance and neighbor
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);

    for(int i=1; i<=m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra();

    for(int i=2; i<=n; i++)
        printf("%lld ", dis[i] + a[i]);

    return 0;
}