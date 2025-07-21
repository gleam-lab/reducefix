#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int N = 2e5 + 10;
const LL INF = LLONG_MAX / 2;

struct Node {
    int to, cost;
    bool operator<(const Node &other) const { return cost > other.cost; }
};

vector<Node> adj[N];

LL dijkstra(int n, int src) {
    priority_queue<Node> pq;
    vector<LL> dist(n + 1, INF);
    dist[src] = 0;
    pq.push({src, 0});
    
    while (!pq.empty()) {
        int u = pq.top().to;
        LL d = pq.top().cost;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &[v, w] : adj[u]) {
            LL nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({v, nd});
            }
        }
    }
    
    return dist[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    for (int i = 2; i <= n; ++i) {
        LL ans = dijkstra(n, i);
        cout << ans << " ";
    }
    
    return 0;
}