#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 2e5 + 5;
const ll INF = 1LL << 60; // Use a safe large value instead of LONG_LONG_MAX

int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii> g[N];

struct node {
    int id;
    ll dis;
    bool operator<(const node& x) const {
        return dis > x.dis;
    }
};

void dijkstra() {
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
        vis[i] = false;
    }
    
    dis[1] = a[1]; // Starting at vertex 1, we must pay its vertex weight
    priority_queue<node> q;
    q.push({1, dis[1]});
    
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        
        if (vis[now.id]) continue;
        vis[now.id] = true;
        
        for (auto &edge : g[now.id]) {
            int neighbor = edge.first;
            ll edge_weight = edge.second;
            ll new_cost = dis[now.id] + edge_weight + a[neighbor];
            
            if (new_cost < dis[neighbor]) {
                dis[neighbor] = new_cost;
                q.push({neighbor, new_cost});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    dijkstra();
    
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    
    return 0;
}