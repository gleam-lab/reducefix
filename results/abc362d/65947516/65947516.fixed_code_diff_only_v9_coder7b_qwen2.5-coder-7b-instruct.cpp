#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii; // Change to store cumulative weight instead of just edge weight
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii>g[N];

// Define a custom comparator for priority queue
struct cmp {
    bool operator()(const pii &a, const pii &b){
        return a.first > b.first;
    }
};

void dijkstra() {
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
        dis[i]=LONG_LONG_MAX;
    dis[1]=0;
    priority_queue<pii,vector<pii>,cmp> pq; // Use min heap based on total weight
    pq.push({0,1}); // Start from vertex 1 with zero cumulative weight
    
    while(!pq.empty()) {
        auto [dist, node] = pq.top(); pq.pop();
        if(vis[node]) continue;
        vis[node] = true;
        
        for(auto [neighbor, weight] : g[node]) {
            if(dist + weight < dis[neighbor]) { // Update only if shorter path found
                dis[neighbor] = dist + weight;
                pq.push({dis[neighbor], neighbor});
            }
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra();
    for(int i=2;i<=n;i++)
        printf("%lld ",dis[i]+a[i]); // Add vertex weight to get final path weight
    return 0;
}